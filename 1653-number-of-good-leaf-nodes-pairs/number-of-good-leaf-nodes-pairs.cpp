/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    vector<int> helper(TreeNode* root, int dis) {
        if (root == nullptr)
            return {};
        vector<int> left = helper(root->left, dis);
        vector<int> right = helper(root->right, dis);
        if (left.size() > 0 && right.size() > 0) {
            for (auto l : left) {
                for (auto r : right) {
                    if (l + r <= dis)
                        ans++;
                }
            }
        }

        if (root->left == nullptr && root->right == nullptr) {
            return {1};
        } else {
            for (auto& l : left) {
                l++;
            }
            for (auto& r : right) {
                r++;
            }
            left.insert(left.end(), right.begin(), right.end());
            return left;
        }
    }

    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        return ans;
    }
};