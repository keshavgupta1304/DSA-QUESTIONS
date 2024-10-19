/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mp;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA)
        {
            mp.insert({tempA,1});
            tempA=tempA->next;
        }
        while(tempB)
        {
            if(mp.find(tempB)!=mp.end())
            {
                return tempB;
            }
            tempB=tempB->next;
        }
        return nullptr;
    }
};