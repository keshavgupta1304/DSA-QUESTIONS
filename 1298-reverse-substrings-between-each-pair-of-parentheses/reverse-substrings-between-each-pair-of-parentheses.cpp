class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                string reverse = "";
                // Pop from the stack until an opening parenthesis is found
                while (!stk.empty() && stk.top() != '(') {
                    reverse += stk.top();
                    stk.pop();
                }
                // Pop the opening parenthesis from the stack
                if (!stk.empty()) {
                    stk.pop();
                }
                // Push the reversed string back onto the stack
                for (char ch : reverse) {
                    stk.push(ch);
                }
            } else {
                stk.push(s[i]);
            }
        }
        
        // Form the result string from the stack
        string ans = "";
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
