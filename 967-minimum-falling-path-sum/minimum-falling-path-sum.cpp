class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n);
        for(int i=0;i<n;i++)
        {
            prev[i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            vector<int> temp(n);
            for(int j=n-1;j>=0;j--)
            {
                int belowRight=j+1>=n?INT_MAX:prev[j+1];
                int belowLeft=j<1?INT_MAX:prev[j-1];
                int below=prev[j];
                temp[j]=matrix[i][j]+min({belowRight,belowLeft,below});
            }
            prev=temp;
        }
        return *min_element(prev.begin(),prev.end());
    }
};