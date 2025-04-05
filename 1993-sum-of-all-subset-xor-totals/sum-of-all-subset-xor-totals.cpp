class Solution {
private:
    void generateSubsets(int index,vector<int> nums,vector<vector<int>>& totalSubsets,vector<int>& subset)
    {
        if(index==nums.size())
        {
            totalSubsets.push_back(subset);
            return;
        }
        //include the element
        subset.push_back(nums[index]);
        generateSubsets(index+1,nums,totalSubsets,subset);
        //exclude the element
        subset.pop_back();
        generateSubsets(index+1,nums,totalSubsets,subset);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> totalSubsets;
        vector<int> subset;
        generateSubsets(0,nums,totalSubsets,subset);
        int result=0;
        for(auto v:totalSubsets)
        {
            int x=0;
            for(auto num:v)
            {
                x=x^num;
            }
            result+=x;
        }
        return result;
    }
};