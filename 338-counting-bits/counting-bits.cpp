class Solution {
public:
    int countSetBits(int num)
    {
        int cnt=0;
        while(num!=0)
        {
            num=num&(num-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        result[0]=0;
        for(int i=1;i<=n;i++)
        {
            result[i]=countSetBits(i);
        }
        return result;

    }
};