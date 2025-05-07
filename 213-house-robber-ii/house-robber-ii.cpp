class Solution {
public:
    int f(vector<int> nums)
    {
        int prev2=0;
        int prev=nums[0];
        int curr=0;
        for(int i=1;i<nums.size();i++)
        {
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notPick=prev;
            curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp=nums;
        temp.erase(temp.begin());
        int ans1=f(temp);
        temp=nums;
        temp.erase(temp.begin()+n-1);
        int ans2=f(temp);
        return max(ans1,ans2);
    }
};