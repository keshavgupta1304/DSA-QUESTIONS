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
    int sum=0;
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
    void traverse(TreeNode* root)
    {
        if(root)
        {
            traverse(root->right);//first traverse the rigthmost largest value and right subtree
            sum+=root->val;//updating sum at eavh node value
            root->val=sum;//updating the node value 
            traverse(root->left);//then traverse the left subtree
        }
    }
};