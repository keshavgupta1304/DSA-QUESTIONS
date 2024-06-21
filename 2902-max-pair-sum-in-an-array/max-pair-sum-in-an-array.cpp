class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int num1 = nums[i], num2 = nums[j];
             
                if(maxEle(num1) == maxEle(num2)){
                    maxSum = max(maxSum, num1 + num2);
                }
            }
        }
        return maxSum == INT_MIN ? -1 : maxSum; 
    }
    int maxEle(int num){
        int maxEl = INT_MIN;
        while(num > 0){
            maxEl = max(maxEl, num % 10);
            num /=10;
        }
        return maxEl;
    }
};