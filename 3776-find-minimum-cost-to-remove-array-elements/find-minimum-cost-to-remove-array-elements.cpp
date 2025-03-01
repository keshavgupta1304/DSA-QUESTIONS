class Solution {
private:
    int recur(int eleLeftIndex,int index,vector<int>& nums,vector<vector<int>>& memo)
    {
        if(index==nums.size()) return nums[eleLeftIndex];
        if(index==nums.size()-1) return max(nums[eleLeftIndex],nums[index]);
        if(memo[index][eleLeftIndex]!=-1) return memo[index][eleLeftIndex];
        int choice1=max(nums[index],nums[index+1])+recur(eleLeftIndex,index+2,nums,memo);
        int choice2=max(nums[eleLeftIndex],nums[index])+recur(index+1,index+2,nums,memo);
        int choice3=max(nums[eleLeftIndex],nums[index+1])+recur(index,index+2,nums,memo);

        return memo[index][eleLeftIndex]=min({choice1,choice2,choice3});

    }
public:
    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return recur(0,1,nums,memo);
    }
};