class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod=1e9+7;
        for(auto &q:queries)
        {
            int l=q[0],r=q[1],k=q[2],v=q[3];
            for(int idx=l;idx<=r;idx+=k)
            {
                nums[idx]=((long long)nums[idx] * v) % (mod);
            }
        }
        int ans=0;
        for(auto &x:nums) ans^=x;
        return ans;
    }
};