class Solution {
private:
    int largestRectangleArea(vector<int> heights) {
        stack<int> stk;
        int maxArea=0;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && heights[stk.top()]>heights[i])
            {
                int ele=stk.top();
                stk.pop();
                int nse=i;
                int pse=stk.empty()?-1:stk.top();
                maxArea=max(maxArea,(nse-pse-1)*heights[ele]);
            }
            stk.push(i);
        }
        while(!stk.empty())
        {
            int nse=n;
            int ele=stk.top();
            stk.pop();
            int pse=stk.empty()?-1:stk.top();
            maxArea=max(maxArea,(nse-pse-1)*heights[ele]);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<vector<int>> prefixSum(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum=0;
                prefixSum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++)
        {
            maxArea=max(maxArea,largestRectangleArea(prefixSum[i]));
        }
        return maxArea;
    }
};