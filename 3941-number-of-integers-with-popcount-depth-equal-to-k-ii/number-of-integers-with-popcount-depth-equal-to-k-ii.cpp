#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    int pop_depth(long long val)
    {
        if(val==1) return 0;
        return 1+pop_depth(__builtin_popcountll(val));
    }
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        vector<ordered_set<int>> vec(6);
        for(int i=0;i<nums.size();i++)
        {
            vec[pop_depth(nums[i])].insert(i);
        }
        vector<int> ans;
        for(auto &q:queries)
        {
            int type=q[0];
            if(type==1)
            {
                int l=q[1];
                int r=q[2];
                int k=q[3];
                ans.push_back(vec[k].order_of_key(r+1)-vec[k].order_of_key(l));
            }
            else
            {
                int idx=q[1];
                long long val=q[2];
                vec[pop_depth(nums[idx])].erase(idx);
                nums[idx]=val;
                vec[pop_depth(nums[idx])].insert(idx);
            }
        }
        return ans;
    }
};