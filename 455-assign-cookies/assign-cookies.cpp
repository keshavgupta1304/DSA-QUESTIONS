class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int i=0;
        int j=0;
        while(i<s.size() && j<g.size())
        {
            if(s[i]>=g[j])
            {
                cnt++;
                i++;
                j++;
            }
            else
            {
                i++;
            }
            
        }
        return cnt;
    }
};