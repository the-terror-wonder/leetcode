class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                int duplicateVal = head->val;
                while (head && head->val == duplicateVal) {
                    head = head->next;
                }
                prev->next = head; 
            } else {
                prev = head;
                head = head->next;
            }
        }

        return dummy->next;
    }
};