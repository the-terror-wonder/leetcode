/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        map<Node*,Node*> mpp;

        Node* ans=new Node(head->val);
        mpp[head]=ans;

        Node* ptr1=head;
        Node* ptr2=ans;

        if(ptr1)ptr1=ptr1->next;

        while(ptr1){
            Node* ele=new Node(ptr1->val);
            ptr2->next=ele;
            ptr2=ptr2->next;

            mpp[ptr1]=ptr2;
            ptr1=ptr1->next;
        }

        ptr1=head;
        ptr2=ans;

        while(ptr1){
            ptr2->random= !(ptr1->random) ? nullptr : mpp[ptr1->random];
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        return ans;

    }
};