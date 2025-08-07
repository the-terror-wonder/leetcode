class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        // `prev` is the tail of the sorted list.
        // `curr` is the node we are considering.
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            // Case 1: The list is already sorted up to this point.
            // Just advance the pointers.
            if (curr->val >= prev->val) {
                prev = curr;
                curr = curr->next;
                continue; // Skip to the next iteration
            }

            // Case 2: `curr` is out of order and must be moved.
            // We need to find where it belongs in the sorted part (dummy -> ... -> prev).

            // First, save the next node to process before we move `curr`.
            ListNode* next_node = curr->next;
            
            // Find the correct insertion spot for `curr`.
            // `finder` will point to the node *before* the insertion point.
            ListNode* finder = dummy;
            while (finder->next->val < curr->val) {
                finder = finder->next;
            }

            // Unlink `curr` from its current position.
            prev->next = next_node;
            
            // Insert `curr` into its correct sorted position.
            curr->next = finder->next;
            finder->next = curr;

            // Move to the next node in the unsorted part of the list.
            curr = next_node;
        }

        return dummy->next;
    }
};