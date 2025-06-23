class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> costMatrix(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            int i=it[0];
            int j=it[1];
            int cost=it[2];
            costMatrix[i][j]=cost;
            costMatrix[j][i]=cost;
        }
        for(int i=0;i<n;i++)
        {
            costMatrix[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j) continue;
                    if(costMatrix[i][k]!=INT_MAX && costMatrix[k][j]!=INT_MAX)
                        costMatrix[i][j]=min(costMatrix[i][j],costMatrix[i][k]+costMatrix[k][j]);
                }
            }
        }
        int leastCount=n;
        int city=0;
        for(int i=0;i<n;i++)
        {
            int reachableCnt=0;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(costMatrix[i][j]!=INT_MAX && costMatrix[i][j]<=distanceThreshold)
                {
                    reachableCnt++;
                }
            }
            if(reachableCnt<=leastCount)
            {
                leastCount=reachableCnt;
                city=i;
            }
        }
        return city;
    }
};