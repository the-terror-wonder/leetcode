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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx = 1;

        ListNode* p = head;

        while (idx < left) {
            p = p->next;
            idx++;
        }

        // return p;

        ListNode* q= nullptr;
        ListNode* r=nullptr;

        ListNode* x=p;

        // return x;

        while(idx<=right && p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
            idx++;
        }

        if(x)x->next=p;
        // return x;

        if(left==1) return q;
        idx=1;

        ListNode* y=head;

        while(idx<left-1){
            y=y->next;
            idx++;
        }
        // return q;

        if(y && q)y->next=q;

        return head;

    }
};