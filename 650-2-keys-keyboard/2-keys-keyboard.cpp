class Solution {
public:
    int minSteps(int n) {
        int minSteps=0;
        int primeFactor=2;//initial prime factor

        while(n>1)
        {
            while(n%primeFactor==0)
            {
                minSteps+=primeFactor;
                n/=primeFactor;
            }
            primeFactor++;
        }
        return minSteps;
    }
};