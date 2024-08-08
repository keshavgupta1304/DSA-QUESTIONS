class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> direc={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> ans;
        for(int step=1,direction=0;ans.size()<rows*cols;step++)
        {
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<step;j++)
                {
                    if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                    {
                        ans.push_back({rStart,cStart});
                    }
                    rStart+=direc[direction][0];
                    cStart+=direc[direction][1];
                }
                direction=(direction+1)%4;
            }
        }
        return ans;
    }
};