#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (!minHeap.empty() && start > minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(end);
        }
        return minHeap.size();
    }
};
