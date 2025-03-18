class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0;
        for(int i=0;i<k;i++)
        {
            leftSum+=cardPoints[i];
        }
        int rightSum=0;
        int n=cardPoints.size();
        int result=leftSum;
        for(int i=k-1;i>=0;i--)
        {
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[i+n-k];
            result=max(result,leftSum+rightSum);
        }
        return result;
    }
};