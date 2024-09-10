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
    int gcd(int a,int b)
    {
        if(b!=0) return gcd(b,a%b);
        else return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans=head;
        if(head->next==nullptr) return head;
        while(head->next)
        {
            int firstVal=head->val;
            int secondVal=head->next->val;
            int gcdNo=gcd(firstVal,secondVal);
            ListNode* gcd=new ListNode(gcdNo);
            // gcd->val=gcdNo;
            gcd->next=head->next;
            head->next=gcd;
            head=head->next->next;
        }
        return ans;
    }
};