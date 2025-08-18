class Solution {
    using ll=long long;
public:
    ll m=1e9+7;

    ll modmul(ll a,ll b)
    {
        return ((a%m)*(b%m))%m;
    } 
    ll modexp(ll a,ll exp)
    {
        ll res=1;
        a%=m;
        while(exp)
        {
            if(exp&1) res=modmul(res,a);
            a=modmul(a,a);
            exp=exp>>1;
        }
        return res;
    }
    ll modinv(ll a){
        return modexp(a,m-2);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int B=300;
        vector<vector<int>> mul(B,vector<int>(n,1));
        for(auto &q:queries)
        {
            int l=q[0],r=q[1],k=q[2],v=q[3];
            if(k>=B)
            {
                for(int i=l;i<=r;i+=k)
                {
                    nums[i]=modmul(nums[i],v);
                }
            }
            else
            {
                mul[k][l]=modmul(mul[k][l],v);
                for(int i=r+1;i<n;i++)
                {
                    if(i%k==l%k)
                    {
                        mul[k][i]=modmul(mul[k][i],modinv(v));
                        break;
                    }
                }
            }
        }
        for(int k=1;k<B;k++)
        {
            for(int st=0;st<k;st++)
            {
                int val=1;
                for(int i=st;i<n;i+=k)
                {
                    val=modmul(val,mul[k][i]);
                    nums[i]=modmul(nums[i],val);
                }
            }
        }
        int ans=0;
        for(auto &x:nums) ans^=x;
        return ans;
    }
};