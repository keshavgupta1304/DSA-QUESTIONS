const int MOD = 1e9+7;
const int MAX=1e5;
vector<long long> fact(MAX,0);
vector<long long> invFact(MAX,0);
class Solution {
public:
    long long power(long long base,long long exp)
    {
        long long result=1;
        while(exp>0)
        {
            if(exp&1) result=(result*base)%MOD;
            base=(base*base)%MOD;
            exp/=2;
        }
        return result;
    }
    long long nCr(int n,int r)
    {
        if(r<0 || r>n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n-r] %MOD;
    }
    Solution()
    {
        if(fact[0]) return;
        fact[0]=1;
        for(int i=1;i<MAX;i++)
        {
            fact[i]=(fact[i-1]*i)%MOD;
        }
        invFact[MAX-1]=power(fact[MAX-1],MOD-2)%MOD;
        for(int i=MAX-2;i>=0;i--)
        {
            invFact[i]=(invFact[i+1]*(i+1))%MOD;
        }
    }
    int countGoodArrays(int n, int m, int k) {
        long long waysToPartition=nCr(n-1,n-k-1)%MOD;
        long long waysToAssignVal=m*power(m-1,n-k-1) % MOD;
        return (waysToPartition*waysToAssignVal)%MOD;
    }
};