class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (s.length() < 2) {
            return 0; 
        }

        int ans = 0;
        string priorityPair = (x > y) ? "ab" : "ba";
        string secondaryPair = (x > y) ? "ba" : "ab";
        int priorityValue = max(x, y);
        int secondaryValue = min(x, y);

        // Function to remove pairs and calculate the gain
        auto removePairs = [&](const string& pair, int value) {
            string result;
            int gain = 0;
            for (char c : s) {
                if (!result.empty() && result.back() == pair[0] && c == pair[1]) {
                    result.pop_back();
                    gain += value;
                } else {
                    result.push_back(c);
                }
            }
            s = result;
            return gain;
        };

        // First remove priority pairs, then secondary pairs
        ans += removePairs(priorityPair, priorityValue);
        ans += removePairs(secondaryPair, secondaryValue);

        return ans;
    }
};
