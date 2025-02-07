class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> result;
        unordered_map<int,int> ballToColor,colorToBallCount;
        for(auto q:queries)
        {
            int ball=q[0];
            int color=q[1];
            if(ballToColor.find(ball)!=ballToColor.end())
            {
                int prevColor=ballToColor[ball];
                if(--colorToBallCount[prevColor]==0) colorToBallCount.erase(prevColor);
            }
            ballToColor[ball]=color;
            colorToBallCount[color]++;
            result.push_back(colorToBallCount.size());
        }
        return result;
    }
};