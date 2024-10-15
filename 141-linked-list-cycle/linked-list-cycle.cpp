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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode* slowptr=head;
        ListNode* fastptr=head;
        while(fastptr!=nullptr && fastptr->next!=nullptr)
        {
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
            if(slowptr==fastptr) return true;
        }
        return false;

    }
};