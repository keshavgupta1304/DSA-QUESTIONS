/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverseLinkedList(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second)
        {
            if(first->val!=second->val)
            {
                reverseLinkedList(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLinkedList(newHead);
        return true;
    }
    ListNode* reverseLinkedList(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode* newHead=reverseLinkedList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
};