class Solution {
private:
    void bfs(int node,vector<int>& visited,const vector<vector<int>> adjacencyList)
    {
        queue<int> q;
        q.push(node);
        visited[node]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adjacencyList[node])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        int n=isConnected[0].size();
        vector<vector<int>> adjacencyList(n+1);
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j])
                {   
                    adjacencyList[i+1].push_back(j+1);
                    adjacencyList[j+1].push_back(i+1);
                } 
            }
        }
        vector<int> visited(n+1);
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                provinces++;
                bfs(i,visited,adjacencyList);
            }
        }
        return provinces;

    }
};