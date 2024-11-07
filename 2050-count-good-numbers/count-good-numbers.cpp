class Solution {
public:
    int modulo=1e9+7;
    long long recursive(long long a,long long n,long long ans)
    {
        if(n==0) return ans;
        if(n&1) return recursive(a,n-1,(ans*a)%modulo);
        return recursive((a*a)%modulo,n/2,ans);
    }
    int countGoodNumbers(long long n) {
        long long ans=recursive(20,n/2,1);
        return (n%2==0)?ans:(ans*5)%modulo;
    }
};