class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddSubarrays = 0;
        int evenSubarrays = 0;
        int result = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] & 1) {
                swap(oddSubarrays, evenSubarrays);
                oddSubarrays++;
            } else {
                evenSubarrays++;
            }
            result = (result % MOD + oddSubarrays % MOD) % MOD;
        }
        return result;
    }
};