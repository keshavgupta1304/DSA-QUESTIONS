class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> seen;  
        stack<int> monoStack;    
        for (int num : nums) {
            if (num == 0) {
                while (!monoStack.empty()) {
                    seen.erase(monoStack.top());
                    monoStack.pop();
                }
                continue;
            }
            while (!monoStack.empty() && monoStack.top() > num) {
                seen.erase(monoStack.top());
                monoStack.pop();
            }
            if (seen.find(num) == seen.end()) {
                ans++;
                seen.insert(num);
            }
            monoStack.push(num);
        }
        return ans;
    }
};