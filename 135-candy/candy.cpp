class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> childrenCandy(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                childrenCandy[i]=1+childrenCandy[i-1];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                if(childrenCandy[i]<=childrenCandy[i+1]) childrenCandy[i]=1+childrenCandy[i+1];
            }
        }
        return accumulate(childrenCandy.begin(),childrenCandy.end(),0);
    }
};