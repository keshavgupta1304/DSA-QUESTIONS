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
    ListNode* findNthNode(ListNode* temp,int n)
    {
        n--;
        while(temp && n)
        {
            temp=temp->next;
            n--;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;
        int len=1;
        ListNode* tail=head;
        while(tail->next)
        {
            len++;
            tail=tail->next;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        ListNode* newLastNode=findNthNode(head,len-k);
        head=newLastNode->next;
        newLastNode->next=nullptr;
        return head;
    }
};