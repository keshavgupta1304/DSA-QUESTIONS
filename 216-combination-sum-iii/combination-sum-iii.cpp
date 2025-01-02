class Solution {
public:
    void recursion(int k, int n,vector<vector<int>> &result,vector<int> &combination,int index,vector<int> nums)
    {
        if(n<0) return;
        if(k==0)
        {
            if(n==0) result.push_back(combination);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]>n) break;
            combination.push_back(nums[i]);
            recursion(k-1,n-nums[i],result,combination,i+1,nums);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        recursion(k,n,result,combination,0,nums);
        return result;
    }
};