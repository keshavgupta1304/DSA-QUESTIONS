class Solution {
public:
    char kthCharacter(int k) {
        int len=1;
        while(len<k) len=len*2;
        int transformations=0;
        while(k!=1)
        {
            if((len/2) < k)
            {
                transformations++;
                k=k-(len/2);
            }
            len=len/2;
        }
        char result='a'+transformations%26;
        return result;
    }
};