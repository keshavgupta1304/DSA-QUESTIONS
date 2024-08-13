class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> combination;
        solve(ans,combination,candidates,target,0);
        return ans;
    }
    void solve(vector<vector<int>>& ans,vector<int>& combination,vector<int>& candidates,int target,int index)
    {
        if(target == 0)
        {
            ans.push_back(combination);
            return;
        }
        for(int i=index;i<candidates.size() && candidates[i]<=target;i++)
        {
            if(i==index || candidates[i]!=candidates[i-1])
            {
                combination.push_back(candidates[i]);
                solve(ans,combination,candidates,target-candidates[i],i+1);
                combination.pop_back();
            }
        }
    }
};