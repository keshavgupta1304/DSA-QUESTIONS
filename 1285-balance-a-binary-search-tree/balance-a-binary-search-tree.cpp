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
    vector<int> sortedValues;
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            sortedValues.push_back(root->val);
            inorder(root->right);
        }
    }
    TreeNode* buildTree(int s,int e)
    {
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(sortedValues[mid]);
        root->left=buildTree(s,mid-1);
        root->right=buildTree(mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        inorder(root);
        return buildTree(0,sortedValues.size()-1);
    }
};