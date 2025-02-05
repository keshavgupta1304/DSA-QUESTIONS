class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool sign = (dividend < 0) == (divisor < 0);
        long n = labs(dividend);
        long d = labs(divisor);
        long quotient = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += (1L << cnt);
            n -= (d << cnt);
        }
        quotient = sign ? quotient : -quotient;
        return quotient > INT_MAX ? INT_MAX : quotient < INT_MIN ? INT_MIN : quotient;
    }
};
