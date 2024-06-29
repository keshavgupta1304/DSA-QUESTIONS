class Solution {
private:
    void dfs(vector<vector<int>>& adjList,int parent,int curr,vector<vector<int>>& ans,vector<bool>& visited)
    {
        visited[curr]=true;
        for(int dest : adjList[curr])
        {
            if(!visited[dest])
            {
                ans[dest].push_back(parent);
                dfs(adjList,parent,dest,ans,visited);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<int>> adjList(n);
        for(const auto& edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
        }

        for(int i=0;i<n;i++)
        {
            vector<bool> visited(n,false);
            dfs(adjList,i,i,ans,visited);
        }
        return ans;
    }
};