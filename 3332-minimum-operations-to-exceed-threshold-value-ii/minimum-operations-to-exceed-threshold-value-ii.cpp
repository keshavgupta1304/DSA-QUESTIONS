class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations=0;
        priority_queue<long long,vector<long long>,greater<long long>> pq(nums.begin(),nums.end());
        while(pq.top()<k)
        {
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            long long ele=x*2 + y;
            pq.push(ele);
            operations++;
        }
        return operations;
    }
};