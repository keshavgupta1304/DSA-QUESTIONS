class Solution {

public:
    void stringReversal(vector<char>& s,int start)
    {
        if(start>=(s.size()-start-1))
        {
            return ;
        }
        swap(s[start],s[s.size()-start-1]);
        start++;
        stringReversal(s,start);
    }
    void reverseString(vector<char>& s) {
        stringReversal(s,0);
    }
};