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
    bool find(TreeNode* node, int value, string& path) {
        if (node->val == value)
            return true;
        if (node->left && find(node->left, value, path))
            path.push_back('L');
        else if (node->right && find(node->right, value, path))
            path.push_back('R');
        return !path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startNode, destNode;
        find(root, startValue, startNode);
        find(root, destValue, destNode);
        while (!startNode.empty() && !destNode.empty() && startNode.back() == destNode.back()) {
            startNode.pop_back();
            destNode.pop_back();
        }
        return string(startNode.size(), 'U') + string(rbegin(destNode), rend(destNode));
    }
};