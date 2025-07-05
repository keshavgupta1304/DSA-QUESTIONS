class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev = triangle[0]; 
        for(int i = 1; i < triangle.size(); i++) {
            prev.push_back(0);
            for(int j = i; j >= 0; j--) {
                if(j == 0) {
                    prev[j] = prev[j] + triangle[i][j]; 
                } else if(j == i) {
                    prev[j] = prev[j-1] + triangle[i][j]; 
                } else {
                    prev[j] = min(prev[j-1], prev[j]) + triangle[i][j];
                }
            }
        }
        return *min_element(prev.begin(), prev.end());
    }
};
