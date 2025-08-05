class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev) prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head != slow ? head : nullptr);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};