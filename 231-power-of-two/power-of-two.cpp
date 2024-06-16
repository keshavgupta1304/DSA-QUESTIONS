class Solution {
public:
    bool isPowerOfTwo(int n) {
        long double m=n;
        if(n==1) return true;
        while(m>1)
        {
            m=m/2;
        }
        if(m==1)
        {
            return true;
        }
        return false;
    }
};