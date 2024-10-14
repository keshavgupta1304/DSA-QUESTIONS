class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> maxHeap;
        for(int i=0;i<nums.size();i++)
        {
            maxHeap.push(nums[i]);
        }
        long long score=0;
        for(int i=0;i<k;i++)
        {
            long long opScore = maxHeap.top();
            maxHeap.pop();
            score+=opScore;
            long long newScore = (opScore+2)/3;
            maxHeap.push(newScore);
        }
        return score;
    }
};