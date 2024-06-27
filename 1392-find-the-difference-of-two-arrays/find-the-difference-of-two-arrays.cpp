class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1,set2;
        unordered_map<int,int> map1;
        for(auto num:nums2)
        {
            map1[num]++;
        }
        for(auto num1:nums1)
        {
            if(map1.find(num1)==map1.end())
            {
                set1.insert(num1);
            }
        }
        vector<int> ans1(set1.begin(),set1.end());
        unordered_map<int,int> map2;
        for(auto num:nums1)
        {
            map2[num]++;
        }
        for(auto num2:nums2)
        {
            if(map2.find(num2)==map1.end())
            {
                set2.insert(num2);
            }
        }
        vector<int> ans2(set2.begin(),set2.end());
        vector<vector<int>> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};