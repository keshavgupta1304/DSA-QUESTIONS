class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> minHeap;
        minHeap.push({0,{0,0}});
        vector<vector<int>> minEffort(m,vector<int>(n,INT_MAX));
        minEffort[0][0]=0;
        vector<pair<int,int>> directions={{-1,0},{0,-1},{0,1},{1,0}};
        while(!minHeap.empty())
        {
            auto ele=minHeap.top();
            minHeap.pop();
            int currEffort=ele.first;
            int currX=ele.second.first;
            int currY=ele.second.second;
            if(currX==m-1 && currY==n-1) return currEffort;
            for(auto [dx,dy]:directions)
            {
                int newX=currX+dx,newY=currY+dy;
                if(newX>=0 && newX<m && newY>=0 && newY<n && 
                max(currEffort,abs(heights[newX][newY]-heights[currX][currY]))
                 < minEffort[newX][newY])
                {
                    minEffort[newX][newY]=max(currEffort,abs(heights[newX][newY]-heights[currX][currY]));
                    minHeap.push({minEffort[newX][newY],{newX,newY}});
                }
            }
        }
        return minEffort[m-1][n-1];
    }
};