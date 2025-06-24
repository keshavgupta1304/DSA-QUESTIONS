class DSU{
    public:
    vector<int> parent,size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DSU ds(n*m);
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]==0) continue;
                for(auto [dx,dy]:dir)
                {
                    int newRow=row+dx;
                    int newCol=col+dy;
                    if(newRow<0 || newRow>=n || newCol<0 || newCol>=m || !grid[newRow][newCol]) continue;
                    int node=row*m+col;
                    int newNode=newRow*m+newCol;
                    ds.unionBySize(node,newNode);
                }
            }
        }
        int maxi=INT_MIN;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]) continue;
                unordered_set<int> components;
                for(auto [dx,dy]:dir)
                {
                    int newRow=row+dx;
                    int newCol=col+dy;
                    if(newRow<0 || newRow>=n || newCol<0 || newCol>=m || !grid[newRow][newCol]) continue;
                    int newNode=newRow*m+newCol;
                    components.insert(ds.findUPar(newNode));
                }
                int islandSize=1;
                for(auto num:components)
                {
                    islandSize+=ds.size[num];
                }
                maxi=max(maxi,islandSize);
            }
        }
        return maxi==INT_MIN?n*m:maxi;
    }
};