class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return gre(word, k) - gre(word, k + 1);
    }
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long gre(string word, int k) {
        long long result = 0;
        int left = 0;
        unordered_map<char, int> mp;
        int consonants = 0;
        for (int right = 0; right < word.size(); right++) {
            char letter = word[right];
            if (isVowel(letter)) {
                mp[letter]++;
            } else {
                consonants++;
            }
            while (mp.size() == 5 && consonants >= k) {
                result += word.size() - right;
                char startingLetter = word[left];
                if (isVowel(startingLetter)) {
                    mp[startingLetter]--;
                    if (mp[startingLetter] == 0) {
                        mp.erase(startingLetter);
                    }
                } else {
                    consonants--;
                }
                left++;
            }
        }
        return result;
    }
};