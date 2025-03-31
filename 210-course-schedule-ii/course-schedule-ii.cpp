class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto &v:prerequisites)
        {
            adjList[v[1]].push_back(v[0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][0]]+=1;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto neighbour:adjList[node])
            {
                if(--indegree[neighbour]==0) q.push(neighbour);
            }
        }
        if(result.size()==numCourses)
        {
            return result;
        }
        else{
            return vector<int>{};
        }
    }
};