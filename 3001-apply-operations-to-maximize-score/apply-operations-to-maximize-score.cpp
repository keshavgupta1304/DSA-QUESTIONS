class Solution {
private:
    vector<int> sieveOfErasthoneses(int num) {
        vector<int> isPrime(num + 1, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        vector<int> primes;
        for (int i = 2; i * i <= num; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= num; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        return primes;
    }
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

public:
    const int MOD = 1e9 + 7;
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScore(n, 0);
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> primes = sieveOfErasthoneses(maxi);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int primeNumber : primes) {
                if (primeNumber * primeNumber > num)
                    break;
                if (num % primeNumber != 0)
                    continue;
                primeScore[i]++;
                while (num % primeNumber == 0)
                    num = num / primeNumber;
            }
            if (num >= 2)
                primeScore[i]++;
        }
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && primeScore[i] > primeScore[stk.top()]) {
                int prevIndex = stk.top();
                stk.pop();
                nextDominant[prevIndex] = i;
            }
            if (!stk.empty())
                prevDominant[i] = stk.top();
            stk.push(i);
        }
        vector<long long> numOfSubarrays(n);
        for (int i = 0; i < n; i++) {
            numOfSubarrays[i] =
                (long long)(nextDominant[i] - i) * (i - prevDominant[i]);
        }
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < n; i++) {
            maxHeap.push({nums[i], i});
        }
        long long score = 1;
        while (k > 0) {
            auto [num, index] = maxHeap.top();
            maxHeap.pop();
            long long operations = min(numOfSubarrays[index], (long long)k);
            score = (score * modPow((long long)num, operations)) % MOD;
            k -= operations;
        }
        return score;
    }
};