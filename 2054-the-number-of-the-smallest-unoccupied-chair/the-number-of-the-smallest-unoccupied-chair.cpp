class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<int> timeToGet=times[targetFriend];
        sort(times.begin(),times.end());

        vector<int> availableTimeOfChair(n,0);

        for(auto val:times)
        {
            for(int i=0;i<n;i++)
            {
                if(val[0]>=availableTimeOfChair[i])
                {
                    availableTimeOfChair[i]=val[1];
                    if(val==timeToGet) return i;
                    break;
                }
            }
        }
        return 0;

    }
};