#include <cstdlib> // for rand()

class Solution {
public:
    ListNode* head;
    
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int result = -1;
        int count = 0;
        ListNode* current = head;
        
        while (current) {
            count++;
            // replace result with current->val with probability 1/count
            if (rand() % count == 0) {
                result = current->val;
            }
            current = current->next;
        }
        return result;
    }
};
