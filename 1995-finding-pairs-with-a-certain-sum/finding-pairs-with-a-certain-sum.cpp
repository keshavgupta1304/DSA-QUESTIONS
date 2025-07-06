class FindSumPairs {
public:
    vector<int> nums1,nums2;
    map<int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(auto num:nums2)
        {
            mp[num]++;
        }
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index]+=val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int totalPairs=0;
        for(int i=0;i<nums1.size();i++)
        {
            if(mp.find(tot-nums1[i])!=mp.end())
            {
                totalPairs+=mp[tot-nums1[i]];
            }
        }
        return totalPairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */