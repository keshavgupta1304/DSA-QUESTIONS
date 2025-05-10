class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        long long sum1=0;
        long long num1Zeros=0;
        for(int i=0;i<n;i++)
        {
            sum1+=nums1[i];
            if(nums1[i]==0) num1Zeros++;
        }
        long long sum2=0;
        long long num2Zeros=0;
        for(int i=0;i<m;i++)
        {
            sum2+=nums2[i];
            if(nums2[i]==0) num2Zeros++;
        }
        if(num2Zeros==0 && num1Zeros==0)
        {
            if(sum1!=sum2) return -1;
            else return sum1;
        }
        if(num2Zeros==0)
        {
            if(sum1>=sum2 || (sum2-sum1)<num1Zeros) return -1;
            else return sum2;
        }
        if(num1Zeros==0)
        {
            if(sum2>=sum1 || (sum1-sum2)<num2Zeros) return -1;
            else return sum1;
        }
        return max(sum1+num1Zeros,sum2+num2Zeros);


    }
};