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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* mover=head;
        while(mover)
        {
            arr.push_back(mover->val);
            mover=mover->next;
        }
        return checkPalindrome(arr);
    }
    bool checkPalindrome(vector<int> arr)
    {
        int n=arr.size();
        for(int i=0;i<n/2;i++)
        {
            if(arr[i]!=arr[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
};