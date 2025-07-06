class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        int N = n / 2;
        vector<vector<int>> left(N + 1), right(N + 1);
        for (int mask = 0; mask < (1 << N); mask++) {
            int size = 0;
            int leftSum = 0;
            int rightSum = 0;
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    size++;
                    leftSum += nums[i];
                    rightSum += nums[i + N];
                }
            }
            left[size].push_back(leftSum);
            right[size].push_back(rightSum);
        }
        for (int size = 0; size <= N; size++) {
            sort(right[size].begin(), right[size].end());
        }
        int res = min(abs(totalSum - 2 * left[N][0]),
                      abs(totalSum - 2 * right[N][0]));
        for (int size = 1; size < N; size++) {
            for (auto& a : left[size]) {
                int size2 = N - size;
                int b = (totalSum - 2 * a) / 2;
                int lowerBound = bs(right[size2], b);
                if (lowerBound != -1) {
                    res = min(res, abs(totalSum -
                                       2 * (a + right[size2][lowerBound])));
                }
            }
        }
        return res;
    }
    int bs(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return ans;
    }
};