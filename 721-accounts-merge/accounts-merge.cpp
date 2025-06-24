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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> emailToGroup;
        DSU ds(n);
        for(int i=0;i<n;i++)
        {
            int accSize=accounts[i].size();
            for(int j=1;j<accSize;j++)
            {
                string email=accounts[i][j];
                if(emailToGroup.find(email)==emailToGroup.end())
                {
                    emailToGroup[email]=i;
                }
                else
                {
                    ds.unionBySize(i,emailToGroup[email]);
                }
            }
        }
        unordered_map<int,vector<string>> mergedGroups;
        for(auto [email,group]:emailToGroup)
        {
            mergedGroups[ds.findUPar(group)].push_back(email);
        }
        vector<vector<string>> result;
        for(auto [group,vec]:mergedGroups)
        {
            vector<string> component={accounts[group][0]};
            component.insert(component.end(),vec.begin(),vec.end());
            sort(component.begin()+1,component.end());
            result.push_back(component);
        }
        return result;
    }
};