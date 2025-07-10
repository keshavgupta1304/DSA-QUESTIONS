class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gaps(n+1,0);
        gaps[0]=startTime[0];
        gaps[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++)
        {
            gaps[i]=startTime[i]-endTime[i-1];
        }
        vector<int> largestRight(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            largestRight[i]=max(largestRight[i+1],gaps[i+1]);
        }
        //largestRight[i]=max in gaps[i+1-->n]
        int largestLeft=0;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int duration=endTime[i-1]-startTime[i-1];
            bool canMergeLeft=duration<=largestLeft;
            bool canMergeRight=duration<=largestRight[i];
            if(canMergeLeft || canMergeRight)
            {
                res=max(res,gaps[i-1]+gaps[i]+duration);
            }
            res=max(res,gaps[i-1]+gaps[i]);
            largestLeft=max(largestLeft,gaps[i-1]);
        }
        return res;
    }
};