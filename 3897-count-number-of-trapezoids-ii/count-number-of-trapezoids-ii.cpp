class Solution {
public:
    int findGcd(int a,int b)
    {
        if(b==0) return a;
        return findGcd(b,a%b);
    }
    pair<int,int> slopeForm(int x1,int y1,int x2,int y2)
    {
        int dx=x1-x2,dy=y1-y2;
        if(dx<=-1)
        {
            dx*=-1,dy*=-1;
        }
        if(dx==0) return {0,1};
        if(dy==0) return {1,0};
        int g=findGcd(abs(dx),abs(dy));
        return {dx/g,dy/g};
    }
    int countTrapezoids(vector<vector<int>>& points) {
        //map to slope to intercept and count
        map<pair<int,int>,map<int,int>> mp;
        //for midpoints
        map<pair<int,int>,int> mids;
        map<pair<int, int>, map<pair<int, int>, int>> mids_diff;
        int pgram=0;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                auto slope=slopeForm(points[i][0],points[i][1],points[j][0],points[j][1]);
                int intercept=slope.first*points[i][1]-slope.second*points[i][0];
                mp[slope][intercept]++;
                int mx=points[i][0]+points[j][0];
                int my=points[i][1]+points[j][1];
                mids[{mx,my}]++;
                mids_diff[{mx,my}][slope]++;
                pgram+=(mids[{mx,my}]-mids_diff[{mx,my}][slope]);
            }
        }
        int ans=0;
        for(auto &[slope,vals]:mp)
        {
            int tot=0,sum=0;
            for(auto &[intercept,cnt]:vals)
            {
                sum+=cnt*tot;
                tot+=cnt;
            }
            ans+=sum;
        }
        return ans-pgram;
    }
};