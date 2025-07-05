class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev;
        prev.push_back(triangle[0][0]);
        for(int i=1;i<triangle.size();i++)
        {
            vector<int> temp;
            for(int j=0;j<=i;j++)
            {
                int upLeft=1e5;
                int up=1e5;
                if(j-1>=0) upLeft=prev[j-1];
                if(j<prev.size()) up=prev[j];
                temp.push_back(min(upLeft,up) + triangle[i][j]);
            }
            prev=temp;
        }
        return *min_element(prev.begin(),prev.end());
    }
};