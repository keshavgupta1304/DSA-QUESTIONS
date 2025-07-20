class Solution {
public:
    bool checkDivisibility(int n) {
        int dSum=0;
        int dprod=1;
        int num=n;
        while(num!=0)
        {
            int digit=num%10;
            dprod*=digit;
            dSum+=digit;
            num=num/10;
        }
        return n%(dSum+dprod)==0;
    }
};