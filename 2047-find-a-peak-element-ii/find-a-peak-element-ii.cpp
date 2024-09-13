class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int element=mat[i][j];
                bool flag=true;
                for(auto direction:directions)
                {
                    int indexi=i+direction[0];
                    int indexj=j+direction[1];
                    if(indexi>=0 && indexj>=0 && indexi<n && indexj<m)
                    {
                        if(mat[indexi][indexj]>=element) flag=false;
                    }
                    if(!flag) break;
                }
                if(flag) return {i,j};
            }
        }
        return {};
    }
};