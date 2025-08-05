class Node {
public: 
    int key, val;
    Node* prev;
    Node* next;

    Node() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    int size;
    map<int, Node*> mpp;
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertNode(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        Node* node = mpp[key];
        deleteNode(node);
        insertNode(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertNode(node);
        } else {
            if (mpp.size() >= size) {
                Node* lru = tail->prev;
                deleteNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertNode(node);
        }
    }
};
