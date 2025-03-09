class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        int n = nums1.size();
        vector<long long> answer(n);
        vector<pair<int, int>> nums1Indexes;
        for (int i = 0; i < n; i++) {
            nums1Indexes.push_back({nums1[i], i});
        }
        sort(nums1Indexes.begin(), nums1Indexes.end(),
             [&](pair<int, int>& a, pair<int, int>& b) {
                 if (a.first == b.first) {
                     return nums2[a.second] > nums2[b.second];
                 }
                 return a.first < b.first;
             });

        priority_queue<int, vector<int>, greater<int>> pq;
        long long maxSum = 0;

        int prevValue = -1;  
        vector<int> temp;    

        for (int j = 0; j < n; j++) {
            int index = nums1Indexes[j].second;
            if (prevValue != -1 && nums1Indexes[j].first != prevValue) {
                sort(temp.rbegin(), temp.rend());
                for (int x = 0; x < min(k, (int)temp.size()); x++) {
                    pq.push(temp[x]);
                    maxSum += temp[x];
                    if (pq.size() > k) {
                        maxSum -= pq.top();
                        pq.pop();
                    }
                }
                temp.clear();
            }
            temp.push_back(nums2[index]);
            answer[index] = maxSum;
            prevValue = nums1Indexes[j].first;
        }
        return answer;
    }
};