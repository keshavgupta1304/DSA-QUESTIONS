class Solution {
private:
    bool isValid(int x,int y, int n)
    {
        return x>=0 && x<n && y>=0 && y<n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> minHeap;
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        minHeap.push({1,{0,0}});
        distance[0][0]=1;
        while(!minHeap.empty())
        {
            auto ele = minHeap.top();
            minHeap.pop();
            int dist=ele.first;
            int currX=ele.second.first;
            int currY=ele.second.second;
            for(int row=-1;row<=1;row++)
            {
                for(int col=-1;col<=1;col++)
                {
                    int newX=currX+row,newY=currY+col;
                    if(isValid(newX,newY,n) && grid[newX][newY]==0 && dist+1<distance[newX][newY])
                    {
                        distance[newX][newY]=dist+1;
                        minHeap.push({distance[newX][newY],{newX,newY}});
                    }
                }
            }
        }
        return distance[n-1][n-1]==INT_MAX?-1:distance[n-1][n-1];
    }
};