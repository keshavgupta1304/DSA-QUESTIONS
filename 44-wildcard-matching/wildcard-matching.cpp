class Solution {
public:
    bool isAllStars(const string& p, int j) {
        for (int i = 0; i <= j; i++) {
            if (p[i] != '*')
                return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m+1,false);
        vector<bool> curr(m+1,false);
        prev[0] = true;
        prev[1]=p[0]=='*';
        for (int j = 2; j <= m; j++) {
            prev[j] = (p[j-1]=='*') & (prev[j-1]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else {
                    if (p[j - 1] == '*')
                        curr[j] = prev[j] ||
                                          curr[j - 1];
                    else
                        curr[j]=false;
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};