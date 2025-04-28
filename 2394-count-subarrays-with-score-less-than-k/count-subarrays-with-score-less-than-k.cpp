class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result=0;
        int left=0;
        int n=nums.size();
        int right=0;
        long long sum=0;
        long long score=0;
        
        while(right<n)
        {
            bool flag=false;
            sum+=(long long)nums[right];
            score=(long long)sum*(right-left+1);
            while(score>=k)
            {
                if(left==right)
                {
                    left++;
                    right++;
                    flag=true;
                    sum=0;
                    break;
                }
                sum-=(long long)nums[left];
                left++;
                score=(long long)sum*(right-left+1);
            }
            if(flag) continue;
            result+=(right-left+1);
            right++;
        }
        return result;
    }
};