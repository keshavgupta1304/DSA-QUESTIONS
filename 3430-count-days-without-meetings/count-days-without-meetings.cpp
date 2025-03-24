class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int currEndTime=0;
        int result=0;
        for(auto meeting:meetings)
        {
            int start=meeting[0];
            int end=meeting[1];
            if(start>currEndTime+1)
            {
                result+=start-currEndTime-1;
            }
            currEndTime=max(currEndTime,end);
        }
        result+=days-currEndTime;
        return result;
    }
};