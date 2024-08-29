class Solution {
private:
    void dfs(vector<vector<int>>& adjacencyList,vector<bool>& visited,int i)
    {
        visited[i]=true;
        for(auto neighbour:adjacencyList[i])
        {
            if(!visited[neighbour])
            {
                dfs(adjacencyList,visited,neighbour);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adjacencyList(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        int noOfComponents=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adjacencyList,visited,i);
                noOfComponents++;
            }
        }
        return n-noOfComponents;
    }
};