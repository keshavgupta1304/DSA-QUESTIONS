class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0;
        int j=n-1;
        
        for(auto wholeRow:matrix)
        {
            while(i<j)
            {
                swap(wholeRow[i],wholeRow[j]);
                i++;
                j--;
            }
        } 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
        reverse(matrix.begin(),matrix.end());
    }
};