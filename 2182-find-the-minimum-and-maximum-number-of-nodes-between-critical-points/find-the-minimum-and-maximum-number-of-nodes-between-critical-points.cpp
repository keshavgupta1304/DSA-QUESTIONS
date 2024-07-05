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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return {-1,-1};
        }
        vector<int> ans;
        int count=2;
        ListNode* temp=head->next;
        ListNode* afterVal=temp->next;
        int value=head->val;
        vector<int> pos;
        while(afterVal!=NULL)
        {

            if(((temp->val)>(value) && (temp->val)>(afterVal->val)) || ((temp->val)<(value) && (temp->val)<(afterVal->val)))
            {
                pos.push_back(count);
            }
            value=temp->val;
            count=count+1;
            temp=afterVal;
            afterVal=afterVal->next;
        }
        if(pos.size()<2)
        {
            return {-1,-1};
        }
        int minValue=INT_MAX;

        for(int i=1;i<pos.size();i++)
        {
            minValue=min(minValue,pos[i]-pos[i-1]);
        }
        ans.push_back(minValue);
        ans.push_back(pos[pos.size()-1]-pos[0]);
        return ans;
    }
};