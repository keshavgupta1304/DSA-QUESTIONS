class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++)
        {
            colors.push_back(colors[i]);
        }
        int n=colors.size();
        int i=0;
        int result=0;
        for(int j=1;j<n;j++)
        {
            if(colors[j]==colors[j-1])
            {
                i=j;
                continue;
            }
            if(j-i+1==k){
                result++;
                i++;
            }
        }
        return result;
    }
};