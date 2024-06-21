class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        sort(nums2.begin(),nums2.end());
        vector<int> visited(n,-1);
        set<int> temp;
        int i=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nums1[i]<nums2[j])
                {
                    break;
                }
                if(visited[i] == -1  && nums1[i]==nums2[j])
                {
                    visited[i]=1;
                    
                    temp.insert(nums1[i]);
                }
            }
        }
        vector<int> ans(temp.begin(), temp.end());
        return ans;
    }
};