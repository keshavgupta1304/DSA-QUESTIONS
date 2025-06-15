class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        if (s.size() == 1) return 8;

        string hi = s;
        for (char x : s) {
            if (x != '9') {
                for (char &c : hi) if (c == x) c = '9';
                break;
            }
        }
        string lo = s;
        if (s[0] == '1') {
            char y = 0;
            for (int i = 1; i < s.size(); ++i)
                if (s[i] != '0' && s[i] != '1') { y = s[i]; break; }
            if (y)
                for (char &c:lo) if (c == y) c = '0';
        } else {
            char y = s[0];
            for (char &c : lo) if (c == y) c = '1';
        }

        return stoi(hi) - stoi(lo);
    }
};
