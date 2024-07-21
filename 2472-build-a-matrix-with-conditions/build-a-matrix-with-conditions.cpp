class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> sortRow=topoSort(rowConditions,k);
        vector<int> sortCol=topoSort(colConditions,k);
        if(sortRow.empty() || sortCol.empty()) return {};
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(sortRow[i]==sortCol[j])
                {
                    ans[i][j]=sortRow[i];
                }
            }
        }
        return ans;

    }
    vector<int> topoSort(vector<vector<int>> rowConditions,int k)
    {
        vector<int> ans;
        //adjaceny list
        vector<vector<int>> adjList(k+1);
        vector<int> indegree(k+1,0);
        for(auto element:rowConditions)
        {
            adjList[element[0]].push_back(element[1]);
            indegree[element[1]]+=1;
        }
       
        queue<int> queue;
        for(int i=1;i<=k;i++)
        {
            if(indegree[i]==0)
            {
                queue.push(i);
            }
        }
        while(!queue.empty())
        {
            int element=queue.front();
            queue.pop();
            ans.push_back(element);
            k--;
            for(auto neighbour:adjList[element])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    queue.push(neighbour);
                }
            }
        }
        if(k!=0) return {};
        return ans;

    }
};