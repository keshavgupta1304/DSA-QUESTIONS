class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int noOfRows=matrix.size();
        int noOfCols=matrix[0].size();
        int elements=noOfRows * noOfCols;
        int start = 0;
        int end = elements - 1;
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            int element=matrix[mid/noOfCols][mid%noOfCols];

            if(element == target)
            {
                return true;
            }            
            else if(element < target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return false;
    }
};