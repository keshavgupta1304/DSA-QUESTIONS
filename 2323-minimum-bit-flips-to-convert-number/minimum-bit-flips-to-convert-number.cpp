class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num=start^goal;
        int noOfOperation=0;
        while(num)
        {
            noOfOperation+=(num&1);
            num=num>>1;
        }
        return noOfOperation;
    }
};