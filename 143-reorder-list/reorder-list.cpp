/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* mid=head;

        while(fast && fast->next){
            fast=fast->next->next;
            mid=mid->next;
        }

        ListNode* p=mid;
        ListNode* q=nullptr;
        ListNode* r;

        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }

        p=head;
        
        ListNode* x=p;
        ListNode* y=q;

        while(p && q && p->next != q){
            x=p;
            y=q;

            p=p->next;
            q=q->next;

            x->next=y;
            y->next=p;
        }

    }
};