class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adjList[n];
        for(auto &flight:flights)
        {
            int from=flight[0];
            int to=flight[1];
            int price=flight[2];
            adjList[from].emplace_back(to,price);
        }
        queue<pair<int,pair<int,int>>> minHeap;
        minHeap.push({0,{src,0}});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(!minHeap.empty()){
            auto ele=minHeap.front();
            minHeap.pop();
            int weight=ele.first;
            int node=ele.second.first;
            int stops=ele.second.second;
            if(stops>k) continue;
            for(auto &e:adjList[node])
            {
                int neighbourNode=e.first;
                int edgeWeight=e.second;
                if(weight+edgeWeight<dist[neighbourNode])
                {
                    if(neighbourNode==dst && stops<=k)
                    {
                        dist[neighbourNode]=weight+edgeWeight;
                    }
                    else if(neighbourNode!=dst && stops+1<=k)
                    {
                        dist[neighbourNode]=weight+edgeWeight;
                        minHeap.push({dist[neighbourNode],{neighbourNode,stops+1}});
                    }
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};