class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>ans(n);
        for(int i =0;i<n;i++){
            ans[i].resize(m);
            for(int j =0;j<m;j++){
                ans[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i]-=ans[i][j];
                colSum[j]-=ans[i][j];

            }
        }
        return ans;
    }
};