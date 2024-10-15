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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowptr=head;
        ListNode* fastptr=head;

        while(fastptr!=nullptr && fastptr->next!=nullptr)
        {
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
            if(slowptr==fastptr)
            {
                slowptr=head;
                while(slowptr!=fastptr)
                {
                    slowptr=slowptr->next;
                    fastptr=fastptr->next;
                }
                return slowptr;
            }
        }
        return nullptr;
    }
};