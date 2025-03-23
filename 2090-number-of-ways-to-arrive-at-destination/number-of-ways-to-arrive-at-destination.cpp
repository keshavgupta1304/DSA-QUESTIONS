class Solution {
public:
    const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjacencyList(n);
        for(auto edge:roads)
        {
            adjacencyList[edge[0]].push_back(make_pair(edge[1],edge[2]));
            adjacencyList[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }
        vector<long long> shortestTime(n,LLONG_MAX);
        shortestTime[0]=0;
        vector<int> countPath(n,0);
        countPath[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> minHeap;
        minHeap.push({0,0});
        while(!minHeap.empty())
        {
            pair<long long,int> ele=minHeap.top();
            minHeap.pop();
            long long currTime=ele.first;
            int currNode=ele.second;
            if(currTime>shortestTime[currNode]) continue;
            for(auto [neighbour,time]:adjacencyList[currNode])
            {
                if(currTime+time<shortestTime[neighbour])
                {
                    shortestTime[neighbour]=currTime+time;
                    countPath[neighbour]=countPath[currNode];
                    minHeap.push({currTime+time,neighbour});
                }
                else if(currTime+time==shortestTime[neighbour])
                {
                    countPath[neighbour]=(countPath[neighbour]+countPath[currNode])%MOD;
                }
            }
        }
        return countPath[n-1];
    }
};