class Solution {
public:
    bool judgeSquareSum(int c) {
        long left=0;
        long right=sqrt(c);
        while(left<=right)
        {
            long check=left*left + right*right;
            if(check==c) return true;
            else if(check > c) right--;
            else left++;
        }

        return false;
    }
};