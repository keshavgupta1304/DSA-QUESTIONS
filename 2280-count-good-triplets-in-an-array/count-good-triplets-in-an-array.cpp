class BIT {
    vector<int> tree;

public:
    BIT(int size) : tree(size + 1, 0) {}

    void update(int index, int val) {
        index++;
        while (index < tree.size()) {
            tree[index] += val;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;

        vector<int> transformed(n);
        for (int i = 0; i < n; ++i)
            transformed[i] = pos[nums1[i]];

        BIT bitLeft(n), bitRight(n);
        vector<int> leftCount(n), rightCount(n);

        for (int i = 0; i < n; ++i) {
            leftCount[i] = bitLeft.query(transformed[i] - 1);
            bitLeft.update(transformed[i], 1);
        }

        long long result = 0;
        for (int i = n - 1; i >= 0; --i) {
            rightCount[i] =
                bitRight.query(n - 1) - bitRight.query(transformed[i]);
            bitRight.update(transformed[i], 1);
            result += 1LL * leftCount[i] * rightCount[i];
        }

        return result;
    }
};