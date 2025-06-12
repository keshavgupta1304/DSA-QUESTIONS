class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=INT_MIN;
        vector<int> temp=nums;
        temp.push_back(nums[0]);
        for(int i=1;i<temp.size();i++)
        {
            int diff=abs(temp[i]-temp[i-1]);
            maxi=max(maxi,diff);
        }
        return maxi;
    }
};