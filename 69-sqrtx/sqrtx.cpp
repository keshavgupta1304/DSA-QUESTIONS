class Solution {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            long long check=mid*mid;
            if(check==x)
            {
                return mid;
            }
            else if(check>x)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return right;
    }
};