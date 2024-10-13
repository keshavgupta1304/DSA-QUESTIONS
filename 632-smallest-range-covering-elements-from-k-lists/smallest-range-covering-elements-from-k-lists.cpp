class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<int> indicesOfLists(k,0);
        vector<int> range={0,INT_MAX};
        while(true)
        {
            int curMin=INT_MAX;
            int curMax=INT_MIN;
            int minNumberInListIndex=0;
            for(int i=0;i<k;i++)
            {
                int currEle=nums[i][indicesOfLists[i]];
                if(currEle<curMin)
                {
                    curMin=currEle;
                    minNumberInListIndex=i;
                }
                if(currEle>curMax)
                {
                    curMax=currEle;
                }
            }
            if((curMax-curMin) < (range[1]-range[0]))
            {
                range[0]=curMin;
                range[1]=curMax;
            }
            indicesOfLists[minNumberInListIndex]++;
            if(indicesOfLists[minNumberInListIndex]==nums[minNumberInListIndex].size())
            {
                break;
            }
        }
        return range;
    }
};