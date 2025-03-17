class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result(n-k+1);
        deque<int> dq;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) result[i+1-k]=nums[dq.front()];
        }
        return result;
    }
};