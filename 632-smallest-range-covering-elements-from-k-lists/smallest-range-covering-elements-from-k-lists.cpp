class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //priority queue to store the smallest number 
        //and its list index with the element index
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<>> minHeap;
        int k=nums.size();
        int curMax=INT_MIN;
        vector<int> range={0,INT_MAX};
        for(int i=0;i<k;i++)
        {
            minHeap.push({nums[i][0],{i,0}});
            curMax=max(curMax,nums[i][0]);
        }
        while(minHeap.size()==k)
        {
            auto [curMin,indices] = minHeap.top();
            minHeap.pop();
            int minListIndex=indices.first;
            int minNumberIndex=indices.second;
            if((curMax-curMin)<(range[1]-range[0]))
            {
                range[0]=curMin;
                range[1]=curMax;
            }
            if(minNumberIndex+1<nums[minListIndex].size())
            {
                minHeap.push({nums[minListIndex][minNumberIndex+1],{minListIndex,minNumberIndex+1}});
                curMax=max(curMax,nums[minListIndex][minNumberIndex+1]);
            }
        }
        return range;
    }
};