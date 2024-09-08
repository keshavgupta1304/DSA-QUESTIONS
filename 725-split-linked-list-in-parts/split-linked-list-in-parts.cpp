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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);

        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        int splitLength = length / k;
        int numRemainingParts = length % k;

        current = head;
        for (int i = 0; i < k; i++) {
            ListNode newPart(0);
            ListNode* tail = &newPart;

            int currentLength = splitLength;
            if (numRemainingParts > 0) {
                numRemainingParts--;
                currentLength++;
            }
            for (int j = 0; j < currentLength; j++) {
                tail->next = new ListNode(current->val);
                tail = tail->next;
                current = current->next;
            }
            ans[i] = newPart.next;
        }

        return ans;
    }
};