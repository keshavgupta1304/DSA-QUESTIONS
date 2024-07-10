class Solution {

public:
    void stringReversal(vector<char>& s,int start,int end)
    {
        if(start>end)
        {
            return ;
        }
        swap(s[start],s[end]);
        start++;
        end--;
        stringReversal(s,start,end);
    }
    void reverseString(vector<char>& s) {
        stringReversal(s,0,s.size()-1);
    }
};