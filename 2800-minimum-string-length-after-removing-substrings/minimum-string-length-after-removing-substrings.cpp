class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (stk.empty()) {
                stk.push(ch);
                continue;
            }

            if (stk.top() == 'A' && ch == 'B') {
                stk.pop();

            } else if (stk.top() == 'C' && ch == 'D') {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        return stk.size();
    }
};