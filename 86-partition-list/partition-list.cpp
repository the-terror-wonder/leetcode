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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ptr=head;
        ListNode* small=new ListNode(0);
        ListNode* big =new ListNode(0);

        ListNode* less=small;
        ListNode* more=big;
        while(ptr){
            if(ptr->val < x){
                less->next=ptr;
                less=less->next;
            }
            else {
                more->next=ptr;
                more=more->next;
            }
            ptr=ptr->next;
        }
        less->next=nullptr;
        more->next=nullptr;

        less->next=big->next;

        return small->next;

    }
};