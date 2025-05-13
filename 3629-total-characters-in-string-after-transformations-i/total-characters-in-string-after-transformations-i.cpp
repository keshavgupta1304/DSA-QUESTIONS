class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        long long result = s.size();
        vector<long long> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            vector<long long> newFreq(26, 0);
            for (int j = 0; j < 26; j++) {
                if (j == 25) { 
                    newFreq[0] = (newFreq[0] + freq[25]) % MOD; 
                    newFreq[1] = (newFreq[1] + freq[25]) % MOD; 
                    result = (result + freq[25]) % MOD; 
                } else {
                    newFreq[j + 1] = (newFreq[j + 1] + freq[j]) % MOD;
                }
            }
            freq = newFreq;
        }

        return result % MOD;
    }
};