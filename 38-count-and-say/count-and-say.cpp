class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s = "1";
        for (int i = 2; i <= n; i++) {
            string t = "";
            for (int j = 0; j < s.length(); j++) {
                int c = 1;
                while (j + 1 < s.length() && s[j] == s[j + 1]) {
                    c++;
                    j++;
                }
                t += to_string(c);
                t += s[j];
            }
            s = t;
        }
        return s;
    }
};