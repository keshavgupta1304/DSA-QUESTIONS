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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;
        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        int posToDelete=count-n+1;
        temp=removeNode(head,posToDelete);
        return temp;
    }
    ListNode* removeNode(ListNode* head,int pos)
    {
        if(pos==1)
        {
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode* prev=nullptr;
        ListNode* temp=head;
        for(int i=0;i<pos-1;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;

    }
};