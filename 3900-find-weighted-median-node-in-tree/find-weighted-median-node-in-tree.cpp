class Solution {
    vector<vector<pair<int,int>>> adjList;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> distFromRoot;
    vector<vector<long long>> upW;
    int LOG;
public:
    void dfs(int node,int parent)
    {
        for(auto ele:adjList[node])
        {
            int children=ele.first;
            int weight=ele.second;
            if(children==parent) continue;
            up[children][0]=node;
            upW[children][0]=weight;
            depth[children]=depth[node]+1;
            distFromRoot[children]=distFromRoot[node]+weight;
            dfs(children,node);
        }
    }
    void buildBinaryLiftingTable(int n)
    {
        for(int j=1;j<LOG;j++)
        {
            for(int v=0;v<n;v++)
            {
                int mid=up[v][j-1];
                if(mid!=-1)
                {
                    up[v][j]=up[mid][j-1];
                    upW[v][j]=upW[v][j-1]+upW[mid][j-1];
                }
            }
        }
    }
    int get_lca(int a,int b)
    {
        if(depth[a]<depth[b]) swap(a,b);
        int k=depth[a]-depth[b];
        for(int j=LOG-1;j>=0;j--)
        {
            if(k & (1<<j))
            {
                a=up[a][j];
            }
        }
        if(a==b) return a;
        for(int j=LOG-1;j>=0;j--)
        {
            if(up[a][j]!=up[b][j])
            {
                a=up[a][j];
                b=up[b][j];
            }
        }
        return up[a][0];
    }
    int climbFromUToLca(int node,long long targetDist)
    {
        long long travelledSoFar=0;
        for(int k=LOG-1;k>=0;k--)
        {
            int upwardNode=up[node][k];
            if(upwardNode!=-1 && travelledSoFar+upW[node][k] < targetDist)
            {
                travelledSoFar+=upW[node][k];
                node=upwardNode;
            }
        }
        return (travelledSoFar>=targetDist) ? node:up[node][0];
    }
    int climbFromVToLca(int node,long long limit)
    {
        long long travelledSoFar=0;
        for(int k=LOG-1;k>=0;k--)
        {
            int upwardNode=up[node][k];
            if(upwardNode!=-1 && travelledSoFar+upW[node][k] <= limit)
            {
                travelledSoFar+=upW[node][k];
                node=upwardNode;
            }
        }
        return node;
    }
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        adjList=vector<vector<pair<int,int>>>(n);
        LOG=0;
        while((1<<LOG) <= n) LOG++;
        up=vector<vector<int>>(n,vector<int>(LOG,-1));
        depth=vector<int>(n,0);
        distFromRoot=vector<long long>(n,0);
        upW=vector<vector<long long>>(n,vector<long long>(LOG,-1));
        for(auto &edge:edges)
        {
            int u=edge[0],v=edge[1],w=edge[2];
            adjList[u].emplace_back(v,w);
            adjList[v].emplace_back(u,w);
        }
        dfs(0,-1);
        buildBinaryLiftingTable(n);

        int len=queries.size();
        vector<int> result(len);
        for(int query=0;query<len;query++)
        {
            int u=queries[query][0];
            int v=queries[query][1];
            int lca=get_lca(u,v);
            long long PathDistance=distFromRoot[u]+distFromRoot[v]-2*distFromRoot[lca];
            long long targetDist=(PathDistance+1)/2;
            long long startToLcaDist=distFromRoot[u]-distFromRoot[lca];
            if(targetDist<=startToLcaDist)
            {
                result[query]=climbFromUToLca(u,targetDist);
            }
            else
            {
                result[query]=climbFromVToLca(v,PathDistance-targetDist);
            }
        }
        return result;
    }
};