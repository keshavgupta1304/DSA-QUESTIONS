class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int startingColor=image[sr][sc];
        if (startingColor == color) return image;
        vector<vector<int>> result(image.begin(),image.end());
        queue<pair<int,int>> q;
        q.push({sr,sc});
        result[sr][sc]=color;
        vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty())
        {
            pair<int,int> currentPixel=q.front();
            q.pop();
            int curX=currentPixel.first;
            int curY=currentPixel.second;
            for(auto [dx,dy]:directions)
            {
                int newX=curX+dx,newY=curY+dy;
                if(newX>=0 && newX<m && newY>=0 && newY<n && result[newX][newY]==startingColor)
                {
                    result[newX][newY]=color;
                    q.push({newX,newY});
                }
            }
        }
        return result;
    }
};