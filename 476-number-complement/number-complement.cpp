class Solution {
public:
    int findComplement(int num) {
        int mask=0;
        int duplicate=num;
        while(duplicate!=0)
        {
            mask=(mask<<1) | 1;
            duplicate=duplicate>>1;
        }
        return (~num)&(mask);

    }
};