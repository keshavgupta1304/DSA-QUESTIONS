class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd_count = 0;
        int even_count = 0;
        int alt_len = 0;
        int last_parity = -1;

        for (int num : nums) {
            int current_parity = num % 2;
            if (current_parity == 0) {
                even_count++;
            } else {
                odd_count++;
            }
            if (current_parity != last_parity) {
                alt_len++;
                last_parity = current_parity;
            }
        }
        return max({odd_count, even_count, alt_len});
    }
};