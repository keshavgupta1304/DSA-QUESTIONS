class Solution {
public:
    int recur(int i,int n,int k,const vector<int>& arr,vector<int>& dp)
    {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int largestSum=0;
        int maxi=0;
        for(int index=i;index<k+i && index<n;index++)
        {
            maxi=max(maxi,arr[index]);
            int currentSum=(index-i+1)*maxi + recur(index+1,n,k,arr,dp);
            largestSum=max(largestSum,currentSum);
        }
        return dp[i]=largestSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return recur(0,n,k,arr,dp);
    }
};