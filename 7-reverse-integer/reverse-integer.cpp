class Solution {
public:
    int reverse(int x) {
        long long reverseNumber=0;
        while(x!=0)
        {
            int digit=x%10;
            x=x/10;
            reverseNumber=reverseNumber*10 + digit;
            if(reverseNumber>=INT_MAX || reverseNumber<=INT_MIN) return 0;

        }
        return static_cast<int>(reverseNumber);
    }
};