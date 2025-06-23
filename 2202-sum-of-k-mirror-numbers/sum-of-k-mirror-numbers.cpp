class Solution {
public:
    bool isPalindromeBaseK(long long num,long long base)
    {
        vector<int> digits;
        while(num)
        {
            digits.push_back(num%base);
            num=num/base;
        }
        int i=0;
        int j=digits.size()-1;
        while(i<j)
        {
            if(digits[i++]!=digits[j--]) return false;
        }
        return true;
    }
    long long makeOddPal(long long num)
    {
        long long ans=num;
        for(long long t=num/10;t>0;t/=10) ans=ans*10+(t%10);
        return ans;
    }
    long long makeEvenPal(long long num)
    {
        long long ans=num;
        for(long long t=num;t>0;t/=10) ans=ans*10+(t%10);
        return ans;
    }
    long long power(long long base,long long exponent)
    {
        long long result=1;
        while(exponent>0)
        {
            if(exponent&1) result=result*base;
            base=base*base;
            exponent>>=1;
        }
        return result;
    }
    long long kMirror(int k, int n) {
        int found=0;
        long long sum=0;
        for(int len=1;found<n;len++)
        {
            int halflen=(len+1)/2;
            long long start=halflen==1?1:power(10,halflen-1);
            long long limit=power(10,halflen);
            for(long long seed=start;seed<limit && found<n;seed++)
            {
                long long num=(len&1)?makeOddPal(seed):makeEvenPal(seed);
                if(isPalindromeBaseK(num,k))
                {
                    found++;
                    sum+=num;
                }
            }
        }
        return sum;
    }
};