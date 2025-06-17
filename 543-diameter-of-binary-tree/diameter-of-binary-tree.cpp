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
    int maxi=0;
    int getHeight(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);
        if(leftHeight!=0 || rightHeight!=0)
        {
            maxi=max(maxi,leftHeight+rightHeight);
        }
        return 1+max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return maxi;
    }
};