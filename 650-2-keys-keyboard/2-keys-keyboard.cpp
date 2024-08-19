class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        return 1 + solve(1,1,n);
    }
    int solve(int currentA,int prevCopy,int n)
    {
        if(currentA==n) return 0;
        if(currentA > n) return 1000;
        int firstChoice=2+solve(currentA*2,currentA,n);
        int secondChoice=1+solve(currentA+prevCopy,prevCopy,n);
        return min(firstChoice,secondChoice);
    }
};