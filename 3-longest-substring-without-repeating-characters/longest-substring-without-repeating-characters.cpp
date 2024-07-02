class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        unordered_set<char> chars; // to store characters in the current window
        int maxSize = 0; // to store the maximum length of substring without repeating characters
        int left = 0, right = 0; // pointers for the sliding window
        
        // sliding window approach
        while (right < s.size()) {
            // if the current character at s[right] is already in the set
            while (chars.find(s[right]) != chars.end()) {
                // remove characters from the set and move the left pointer to the right
                chars.erase(s[left]);
                ++left;
            }
            
            // update the maximum length found so far
            maxSize = max(maxSize, right - left + 1);
            
            // add the current character to the set and move the right pointer to the right
            chars.insert(s[right]);
            ++right;
        }
        
        return maxSize;
    }
};