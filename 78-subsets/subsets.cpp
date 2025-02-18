class Solution {
private:
    void recursion(vector<vector<int>>& ans,vector<int>& subset,int index,vector<int> nums)
    {
        if(index>=nums.size())
        {
            ans.push_back(subset);
            return;
        }
        //include
        subset.push_back(nums[index]);
        recursion(ans,subset,index+1,nums);
        subset.pop_back();
        //exclude
        recursion(ans,subset,index+1,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        recursion(ans,subset,0,nums);
        return ans;
    }
};