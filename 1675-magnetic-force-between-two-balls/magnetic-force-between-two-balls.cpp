class Solution {
public:

    bool isPossibleSol(vector<int>& position, int m,int mid)
    {
        int ballCount=1;
        int lastPos=position[0];
        for(int i=0;i<position.size();i++)
        {
            if(position[i]-lastPos>=mid)
            {
                ballCount++;
                if(ballCount==m)
                {
                    return true;
                }
                lastPos=position[i];
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        long long left=0;
        sort(position.begin(), position.end());
        long long max=*max_element(position.begin(), position.end());
        long long right=max;
        long long ans=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossibleSol(position,m,mid))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};