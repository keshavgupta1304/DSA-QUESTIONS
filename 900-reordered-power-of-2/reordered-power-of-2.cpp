class Solution {
public:
    bool reorderedPowerOf2(int n) {
        static vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; 
        auto get_sign = [&](int num) {
            long long sign = 1;
            while (num > 0) {
                int digit = num % 10;
                sign *= primes[digit];
                num /= 10;
            }
            return sign;
        };
        static unordered_set<long long> power_signs;
        if (power_signs.empty()) {
            for (int i = 0; i < 31; i++) {
                power_signs.insert(get_sign(1 << i));
            }
        }
        return power_signs.count(get_sign(n));
    }
};
