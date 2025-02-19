class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater=0;
        int n=height.size();
        vector<int> prefixMax(n);
        prefixMax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            prefixMax[i]=max(prefixMax[i-1],height[i]);
        }
        vector<int> suffixMax(n);
        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixMax[i]=max(suffixMax[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        {
            int leftMax=prefixMax[i],rightMax=suffixMax[i];
            if(height[i]<leftMax && height[i]<rightMax)
            {
                totalWater+=min(leftMax,rightMax)-height[i];
            }
        }
        return totalWater;
    }
};