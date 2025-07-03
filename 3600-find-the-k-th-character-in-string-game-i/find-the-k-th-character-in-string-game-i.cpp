class Solution {
public:
    char kthCharacter(int k) {
        int add = 0;
        int len = 1 << (31 - __builtin_clz(k));
        while (k != 1) {
            if (k > len) {
                k -= len;
                add++;
            }
            len = len >> 1;
        }

        return char('a' + (add % 26));
    }
};
