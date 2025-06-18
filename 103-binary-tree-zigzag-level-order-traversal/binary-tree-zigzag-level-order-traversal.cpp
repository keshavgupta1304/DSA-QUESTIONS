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
    void helper(TreeNode* root,vector<vector<int>>& result)
    {
        queue<TreeNode*> q;
        q.push(root);
        int isLeft=1;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> levelNodes(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                int index=isLeft?i:size-i-1;
                levelNodes[index]=node->val;
            }
            result.push_back(levelNodes);
            isLeft^=1;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        helper(root,result);
        return result;
    }
};