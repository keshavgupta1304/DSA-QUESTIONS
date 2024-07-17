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
private:
    TreeNode* solve(TreeNode* node,unordered_set<int>& toDelete,vector<TreeNode*>& forest)
    {
        if(!node)
        {
            return nullptr;
        }
        node->left=solve(node->left,toDelete,forest);
        node->right=solve(node->right,toDelete,forest);
        if(toDelete.find(node->val)!=toDelete.end())
        {
            if(node->left)
            {
                forest.push_back(node->left);
            }
            if(node->right)
            {
                forest.push_back(node->right);
            }
            delete node;
            return nullptr;
        }
        return node;

    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete(to_delete.begin(),to_delete.end());
        vector<TreeNode*> forest;

        root=solve(root,toDelete,forest);
        if(root)
        {
            forest.push_back(root);
        }
        return forest;
    }
};