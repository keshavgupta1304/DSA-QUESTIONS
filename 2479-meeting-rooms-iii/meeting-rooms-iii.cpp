class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<long long> roomAvailableTime(n,0);
        vector<int> meetingCount(n,0);
        for(auto & meeting:meetings)
        {
            int startTime=meeting[0];
            int endTime=meeting[1];
            bool isRoomFree=false;
            long long minFreeTime=LLONG_MAX;
            int minFreeRoom=0;
            for(int i=0;i<n;i++)
            {
                if(startTime>=roomAvailableTime[i])
                {
                    isRoomFree=true;
                    meetingCount[i]++;
                    roomAvailableTime[i]=endTime;
                    break;
                }
                if(minFreeTime>roomAvailableTime[i])
                {
                    minFreeTime=roomAvailableTime[i];
                    minFreeRoom=i;
                }
            }
            if(!isRoomFree)
            {
                roomAvailableTime[minFreeRoom]+=endTime-startTime;
                meetingCount[minFreeRoom]++;
            }
        }
        int maxMeetingRoom=0;
        int maxMeetingCount=0;
        for(int i=0;i<n;i++)
        {
            if(meetingCount[i]>maxMeetingCount)
            {
                maxMeetingCount=meetingCount[i];
                maxMeetingRoom=i;
            }
        }
        return maxMeetingRoom;
    }
};