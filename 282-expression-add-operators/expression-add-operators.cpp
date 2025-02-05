class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string currentExpression;
        backtrack(num, target, 0, 0, 0, currentExpression, result);
        return result;
    }

private:
    void backtrack(const string& num, int target, int index,
                   long long currentValue, long long lastValue,
                   string& currentExpression, vector<string>& result) {
        if (index == num.size()) {
            if (currentValue == target) {
                result.push_back(currentExpression);
            }
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            if (i > index && num[index] == '0')
                break;
            string currentNumStr = num.substr(index, i - index + 1);
            long long currentNum = stoll(currentNumStr);
            if (index == 0) {
                currentExpression = currentNumStr;
                backtrack(num, target, i + 1, currentNum, currentNum,
                          currentExpression, result);
            } else {
                currentExpression += '+' + currentNumStr;
                backtrack(num, target, i + 1, currentValue + currentNum,
                          currentNum, currentExpression, result);
                currentExpression.erase(currentExpression.size() -
                                        currentNumStr.size() - 1);
                currentExpression += '-' + currentNumStr;
                backtrack(num, target, i + 1, currentValue - currentNum,
                          -currentNum, currentExpression, result);
                currentExpression.erase(currentExpression.size() -
                                        currentNumStr.size() - 1);
                currentExpression += '*' + currentNumStr;
                backtrack(num, target, i + 1,
                          currentValue - lastValue + (lastValue * currentNum),
                          lastValue * currentNum, currentExpression, result);
                currentExpression.erase(currentExpression.size() -
                                        currentNumStr.size() - 1);
            }
        }
    }
};