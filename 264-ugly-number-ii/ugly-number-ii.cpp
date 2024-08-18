class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> storeUgly;
        storeUgly.insert(1);
        long currentuglyNumber=1;

        for(int i=0;i<n;i++)
        {
            currentuglyNumber=*(storeUgly.begin());
            storeUgly.erase(storeUgly.begin());
            storeUgly.insert(currentuglyNumber*2);
            storeUgly.insert(currentuglyNumber*3);
            storeUgly.insert(currentuglyNumber*5);
        }
        return (int)currentuglyNumber;
    }
};