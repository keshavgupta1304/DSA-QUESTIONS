class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> mp, windowMp;
        for (char ch : t) mp[ch]++;

        int left = 0, leftIndex = 0, rightIndex = INT_MAX;
        int matchCount = 0; 
        for (int right = 0; right < s.size(); right++) {
            if (mp.find(s[right]) != mp.end()) {
                windowMp[s[right]]++;
                if (windowMp[s[right]] == mp[s[right]]) {
                    matchCount++;
                }
            }
            while (matchCount == mp.size()) { 
                if (rightIndex == INT_MAX || (rightIndex - leftIndex) > (right - left)) {
                    leftIndex = left;
                    rightIndex = right;
                }
                if (mp.find(s[left]) != mp.end()) {
                    if (windowMp[s[left]] == mp[s[left]]) {
                        matchCount--; 
                    }
                    windowMp[s[left]]--;
                }
                left++; 
            }
        }
        return rightIndex == INT_MAX ? "" : s.substr(leftIndex, rightIndex - leftIndex + 1);
    }
};
