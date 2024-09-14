class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(n!=m) return false;
        string to_check=s+s;
        if(to_check.find(goal)==string::npos)
        {
            return false;
        }
        return true;
    }
};