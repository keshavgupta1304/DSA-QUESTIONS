class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++) {
            if (stk.empty() || nums[i] <= nums[stk.top()]) {
                stk.push(i);
            }
        }
        int maxWidth = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= nums[stk.top()]) {
                maxWidth = max(maxWidth, i - stk.top());
                stk.pop();
            }
        }
        return maxWidth;
    }
};