class Solution {
public:
    bool canPartition(string stringNum, int target) {
        if (stringNum == "" && target == 0) return true;
        if (target < 0) return false;
        for (int index = 0; index < stringNum.size(); index++) {
            string left = stringNum.substr(0, index + 1);
            string right = stringNum.substr(index + 1);
            int leftNum = stoi(left);

            if (canPartition(right, target - leftNum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            if (canPartition(to_string(squareNum), currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};