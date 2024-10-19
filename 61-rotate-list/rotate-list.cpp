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
    void Reverse(vector<int>& arr, int start, int end)
    {
        while (start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    void rotateRight(vector<int>& arr,int k,int n)
    {
        k=k%n;
        if(k==0) return ;
        Reverse(arr,0,n-k-1);
        Reverse(arr,n-k,n-1);
        Reverse(arr,0,n-1);
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        if(n==0) return nullptr;
        rotateRight(arr,k,n);
        temp=head;
        int i=0;
        while(temp)
        {
            temp->val=arr[i++];
            temp=temp->next;
        }
        return head;
    }
};