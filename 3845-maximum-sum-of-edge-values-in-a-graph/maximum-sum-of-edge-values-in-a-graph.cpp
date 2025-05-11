class Solution {
public:
    bool hasCycle(int currNode,int parent,const vector<vector<int>>& adjList,int& size,vector<bool>& visited)
    {
        visited[currNode]=true;
        size++;
        for(auto neighbour:adjList[currNode])
        {
            if(!visited[neighbour])
            {
                if(hasCycle(neighbour,currNode,adjList,size,visited)) return true;
            }
            else if(neighbour!=parent) return true;
        }
        return false;
    }
    long long solve(int componentSize,int& currentValue,bool isCycle)
    {
        vector<long long> values(componentSize,0);
        int startValue=currentValue-componentSize+1;
        int i=0;
        for(i=0;i<componentSize/2;i++)
        {
            values[i]=startValue++;
            values[componentSize-i-1]=startValue++;
        }
        if(componentSize&1) values[i]=startValue;
        long long score=0;
        for(int i=1;i<componentSize;i++)
        {
            score+=values[i]*values[i-1];
        }
        if(isCycle) score+=values[0]*values[componentSize-1];
        currentValue=currentValue-componentSize;
        return score;
    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<pair<int,int>> cyclicComponents,acyclicComponents;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int size=0;
                if(hasCycle(i,-1,adjList,size,visited))
                {
                    cyclicComponents.push_back({size,i});
                }
                else
                {
                    acyclicComponents.push_back({size,i});
                }
            }
        }
        sort(cyclicComponents.rbegin(),cyclicComponents.rend());
        sort(acyclicComponents.rbegin(),acyclicComponents.rend());
        int currentValue=n;
        long long maxScore=0;
        for(auto [componentSize,startNode]:cyclicComponents)
        {
            maxScore+=solve(componentSize,currentValue,true);
        }
        for(auto [componentSize,startNode]:acyclicComponents)
        {
            maxScore+=solve(componentSize,currentValue,false);
        }
        return maxScore;
    }
};