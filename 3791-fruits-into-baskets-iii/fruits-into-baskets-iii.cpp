class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int result = 0;
        int unplaced = INT_MAX;
        for (const auto fruit: fruits) {
            if (fruit >= unplaced) {
                ++result;
                continue;
            }
            bool flag = false;
            for (auto it = baskets.begin(); it != baskets.end(); ++it) {
                if (fruit <= *it) {
                    baskets.erase(it);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                unplaced = min(unplaced, fruit);
                ++result;
            }
        }
        return result;
    }
};