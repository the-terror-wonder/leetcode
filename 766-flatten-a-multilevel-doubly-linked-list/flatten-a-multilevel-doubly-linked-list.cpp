/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) nullptr;

        Node* ptr=head;

        while(ptr){
            
            if(ptr->child){
                ptr->child=flatten(ptr->child);
                Node* first=ptr->child;
                Node* last=ptr->child;
                while(last->next) last=last->next;

                last->next=ptr->next;
                if(last->next) last->next->prev=last;

                ptr->next=ptr->child;
                ptr->next->prev=ptr;

                ptr->child=nullptr;
            }

            ptr=ptr->next;
        }

        return head;
    }
};