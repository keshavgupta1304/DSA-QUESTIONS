class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        int targetSize=n/3;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        vector<int> array;
        int isPossible=true;
        for(int i=0;i<=n;i++)
        {
            if(i%3==0)
            {
                if(!array.empty()) result.push_back(array);
                array={nums[i]};
            } 
            else if(nums[i]-nums[i-1]<=k)
            {
                if(i%3==2)
                {
                    if(nums[i]-nums[i-2]<=k) array.push_back(nums[i]);
                    else
                    {
                        isPossible=false;
                        break;
                    }
                }
                else
                {
                    array.push_back(nums[i]);
                }
            }
            else
            {
                isPossible=false;
                break;
            } 
        }
        if(!isPossible) return vector<vector<int>>{};
        return result;
    }
};