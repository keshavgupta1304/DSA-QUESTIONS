class Solution {
public:
    bool isPalindrome(int x) {
        long long revNum = 0;
    // Create a duplicate variable to
    // store the original number
    int dup = x;
    // Iterate through each digit of
    // the number until it becomes 0
    while (x > 0) {
        // Extract the last
        // digit of the number
        int ld = x % 10;
        // Build the reverse number
        // by appending the last digit
        revNum = (revNum * 10) + ld;
        // Remove the last digit
        // from the original number
        x = x / 10;
    }
    // Check if the original number
    // is equal to its reverse
    if (dup == (int)revNum) {
        // If equal, return true
        // indicating it's a palindrome
        return true;
    } else {
        // If not equal, return false
        // indicating it's not a palindrome
        return false;
    }
    }
};