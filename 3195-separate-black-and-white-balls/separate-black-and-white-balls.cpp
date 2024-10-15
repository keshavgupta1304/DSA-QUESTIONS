class Solution {
public:
    long long minimumSteps(string s) {
        int posToPlaceZero=0;
        long long minSteps=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                minSteps+=i-posToPlaceZero;
                posToPlaceZero++;
            }
        }
        return minSteps;
    }
};