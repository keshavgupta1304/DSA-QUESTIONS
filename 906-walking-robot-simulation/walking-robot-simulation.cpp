class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        map<vector<int>,int> mp;
        for(auto positionObstacle:obstacles)
        {
            mp.insert({positionObstacle,1});
        }
        int maxDistance = 0;
        vector<int> currentPos = {0,0};
        int currentDirection=0;
        for(auto val:commands)
        {
            if(val==-1)
            {
                currentDirection=(currentDirection+1)%4;
                continue;
            }
            if(val==-2)
            {
                currentDirection=(currentDirection-1);
                if(currentDirection<0) currentDirection=3;
                continue;
            }
            for(int steps=0;steps<val;steps++)
            {
                int nextX = currentPos[0] + directions[currentDirection][0];
                int nextY = currentPos[1] + directions[currentDirection][1];
                if(mp.find({nextX,nextY})!=mp.end())
                {
                    break;
                }
                currentPos[0]=nextX;
                currentPos[1]=nextY;
            }
            maxDistance=max(maxDistance,currentPos[0]*currentPos[0]+currentPos[1]*currentPos[1]);
        }
        return (int)maxDistance;
    }
};