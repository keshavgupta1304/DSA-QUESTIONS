class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            string add = "";
            for (char c : word) {
                add += (c - 'a' + 1) % 26 + 'a';
            }
            word += add;
        }
        return word[k - 1];
    }
};
