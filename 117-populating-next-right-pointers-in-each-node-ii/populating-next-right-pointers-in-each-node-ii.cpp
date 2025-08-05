/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;

        q.push(root);

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            int n=q.size();

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);

            for(int i=0;i<n;i++){
                Node* ele=q.front();
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);

                q.pop();
                front->next=ele;
                front=front->next;
            }
        }

        return root;
    }
};