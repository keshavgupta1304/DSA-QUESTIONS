class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //This deque helps track the minimum element within the current window that satisfies the limit condition.
        deque<int> increase;
        deque<int> decrease;//This deque helps track the maximum element within the current window that satisfies the limit condition
        int max_len = 0;//store the length of the longest valid subarray found so far.
        int left = 0;//track of the starting index of the current window.

        for (int right = 0; right < nums.size(); ++right) {
            while (!increase.empty() && nums[right] < increase.back()) {
                increase.pop_back();//increase always holds in asc order
            }
            increase.push_back(nums[right]);

            while (!decrease.empty() && nums[right] > decrease.back()) {
                decrease.pop_back();//decrease always holds in desc order
            }
            decrease.push_back(nums[right]);

            while (decrease.front() - increase.front() > limit) {//shrinking window if condtn violates
                if (nums[left] == decrease.front()) {
                    decrease.pop_front();
                }
                if (nums[left] == increase.front()) {
                    increase.pop_front();
                }
                ++left;//shrinking the window 
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};