class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       vector<int>::iterator it;
       vector<int> ans;
       for(int num:nums1)
       {
            it=find(nums2.begin(),nums2.end(),num);
            if(it!=nums2.end())
            {
                ans.push_back(num);
                nums2[it-nums2.begin()]=-1;
            }
       }
       return ans;

    }
};