class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> binary(n);
        int count=0;
        int i=0;
        for(i=0;i<32;i++)
        {
            if(binary[i]^0)
            {
                count++;
            }
        }
        return count;
    }
};