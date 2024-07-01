class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       if(arr.size() < 3)
       {
        return false;
       }
       int consecutiveOdds=0;
       int window_size=3;
       for(int i=0;i<window_size;i++)
       {
            if(arr[i] & 1)
            {
                consecutiveOdds++;
            }
       }

       if(consecutiveOdds == window_size)
       {
            return true;
       }
       for(int i=window_size;i<arr.size();i++)
       {
            if(arr[i-window_size] & 1)
            {
                consecutiveOdds--;
            }
            if(arr[i] & 1)
            {
                consecutiveOdds++;
            }
            if(consecutiveOdds == 3)
            {
                return true;
            }
       }
       return false;


    }
};