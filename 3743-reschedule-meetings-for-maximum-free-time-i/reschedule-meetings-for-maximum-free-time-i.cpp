class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gaps(n+1,0);
        gaps[0]=startTime[0];
        gaps[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++)
        {
            gaps[i]=startTime[i]-endTime[i-1];
        }
        // for(int i=0;i<=n;i++) cout<<gaps[i]<<" ";
        int windowSum=0;
        for(int i=0;i<=k;i++)
        {
            windowSum+=gaps[i];
        }
        int res=windowSum;
        int start=0;
        for(int end=k+1;end<=n;end++)
        {
            windowSum+=gaps[end];
            if(end-start==k+1)
            {
                windowSum-=gaps[start];
                start++;
            }
            res=max(res,windowSum);
        }
        return res;
    }
};