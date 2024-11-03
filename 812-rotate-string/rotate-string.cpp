class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(n!=m) return false;
        string check=s+s;
        if(check.find(goal)!=string::npos) return true;
        return false;
    }
};