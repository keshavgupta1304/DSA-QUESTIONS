class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(make_pair(e[1], e[2]));
            adj[e[1]].push_back(make_pair(e[0], 2 * e[2]));
        }

        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(pq.size()) {
            auto [d,v] = pq.top();
            pq.pop();
            if(dist[v] != INT_MAX) continue;
            dist[v] = d;
            for(auto [x,w] : adj[v]) {
                if(dist[x] == INT_MAX)
                    pq.push({w + d,x});
            }
        }
        if(dist.back() == INT_MAX) {
            return -1;
        }
        else{
            return dist.back();
        }
    }
};