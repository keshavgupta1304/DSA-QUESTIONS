class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> duplicate(nums);
        sort(duplicate.begin(),duplicate.end());
        int i=0;
        for(i=0;i<duplicate.size()-1;i++)
        {
            if(duplicate[i]==duplicate[i+1])
            {
                break;
            }
        }
        return duplicate[i];

    }
};