class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int lastDay=0;
        for(auto &e:events)
        {
            lastDay=max(lastDay,e[1]);
        }
        int i=0;
        int cnt=0;
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int day=1;day<=lastDay;day++)
        {
            while(i<n && events[i][0]==day)
            {
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<day)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                cnt++;
                pq.pop();
            }
            if(i==n && pq.empty()) break;
        }
        return cnt;
    }
};