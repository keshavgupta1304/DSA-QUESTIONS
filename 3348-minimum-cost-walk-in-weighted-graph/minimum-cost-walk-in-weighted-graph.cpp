class Solution {

public:
    vector<int> parent;
    vector<int> depth;
    int find(int node)
    {
        if(parent[node]==-1) return node;
        parent[node]=find(parent[node]);
        return parent[node];
    }
    void Union(int node1,int node2)
    {
        int root1=find(node1);
        int root2=find(node2);
        if(root1==root2)
        {
            return;
        }
        if(depth[root1]<depth[root2]) swap(root1,root2);
        parent[root2]=root1;
        if(depth[root1]==depth[root2]) depth[root1]++;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> result;
        parent.resize(n,-1);
        depth.resize(n,0);
        vector<unsigned int> cost(n,-1);
        for(auto edge:edges)
        {
            Union(edge[0],edge[1]);
        }
        for(auto edge:edges)
        {
            int root=find(edge[0]);
            cost[root]&=edge[2];
        }
        for(auto q:query)
        {
            int s=q[0];
            int e=q[1];
            if(find(s)!=find(e)) result.push_back(-1);
            else result.push_back(cost[find(s)]);
        }
        return result;
    }
};