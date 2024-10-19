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
private:
    ListNode* middleLL(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeLL(ListNode* head1,ListNode* head2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }
            else
            {
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
        }
        if(head1) temp->next=head1;
        if(head2) temp->next=head2;
        return dummy->next;

    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode* middleNode=middleLL(head);
        ListNode* leftHead=head;
        ListNode* rightHead=middleNode->next;
        middleNode->next=nullptr;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        return mergeLL(leftHead,rightHead);
    }
};