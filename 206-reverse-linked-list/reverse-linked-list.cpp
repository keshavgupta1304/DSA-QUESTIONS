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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* prev2=nullptr;
        ListNode* prev=nullptr;
        ListNode* temp=head;

        while(temp)
        {
            prev2=prev;
            prev=temp;
            temp=temp->next;
            prev->next=prev2;
        }
        return prev;
    }
};