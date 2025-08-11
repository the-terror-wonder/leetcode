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
    ListNode* reverse(ListNode* list) {
        ListNode* p = list;
        ListNode* q = nullptr;
        ListNode* r;

        while (p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        return q;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* rl1 = reverse(l1);
        ListNode* rl2 = reverse(l2);

        ListNode* d = new ListNode();
        ListNode* ptr = d;
        int carry = 0;
        while (rl1 && rl2) {
            int data = (rl1->val) + (rl2->val) + carry;

            carry = data / 10;
            data %= 10;

            ListNode* ele = new ListNode(data);
            ptr->next = ele;
            ptr = ptr->next;
            rl1 = rl1->next;
            rl2 = rl2->next;
        }

        if (rl1) {
            while (rl1 && carry > 0) {
                int data = (rl1->val) + carry;

                carry = data / 10;
                data%=10;
                ListNode* ele = new ListNode(data);
                ptr->next = ele;
                ptr = ptr->next;
                rl1 = rl1->next;
            }
            if (rl1)
                ptr->next = rl1;
        }
        if (rl2) {
            while (rl2 && carry > 0) {
                int data = (rl2->val) + carry;

                carry = data / 10;
                data%=10;
                ListNode* ele = new ListNode(data);
                ptr->next = ele;
                ptr = ptr->next;
                rl2 = rl2->next;
            }
            if (rl2)
                ptr->next = rl2;
        }
        while(ptr && ptr->next)ptr=ptr->next;
        if(carry>0){
            ptr->next = new ListNode(carry);
        }

        return reverse(d->next);
    }
};