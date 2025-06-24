class DSU{
    vector<int> parent,size;
    public:
    DSU(int n)
    {
        parent=vector<int>(n+1);
        size=vector<int>(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findUPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUPar(parent[u]);
    }
    void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges+1<n) return -1;
        int ans=0;
        DSU ds(n);
        for(auto edge:connections)
        {
            ds.unionBySize(edge[0],edge[1]);
        }
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i)==i)
            {
                ans++;
            }
        }
        return ans-1;
    }
};