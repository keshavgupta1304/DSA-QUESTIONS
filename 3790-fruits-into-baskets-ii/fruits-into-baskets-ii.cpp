class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=baskets.size();
        // multiset<int> bask(baskets.begin(),baskets.end());
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int quantity=fruits[i];
            for(int j=0;j<m;j++)
            {
                if(baskets[j]>=quantity){
                    baskets[j]=0;
                    cnt++;
                    break;
                }
            }
        }
        return m-cnt;
    }
};