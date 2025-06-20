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
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        int lh=depth(root->left);
        int rh=depth(root->right);
        return 1+max(lh,rh);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        int dep=depth(root);
        int l=0;
        while(!q.empty())
        {
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                // if(node->left==nullptr && node->right==nullptr) continue;
                if(node->left!=nullptr && node->right==nullptr)
                {
                    q.push(node->left);
                    TreeNode* newNode=new TreeNode(-101);
                    q.push(newNode);
                }
                else if(node->left==nullptr && node->right!=nullptr)
                {
                    TreeNode* newNode=new TreeNode(-101);
                    q.push(newNode);
                    q.push(node->right);
                }
                else if(node->left!=nullptr && node->right!=nullptr)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    if(l+1<dep)
                    {
                        TreeNode* newNode1=new TreeNode(-101);
                        TreeNode* newNode2=new TreeNode(-101);
                        q.push(newNode1);
                        q.push(newNode2);
                    }
                }
                level.push_back(node->val);
            }
            l++;
            for(int i=0;i<level.size()/2;i++)
            {
                if(level[i]!=level[level.size()-i-1]) return false;
            }
        }
        return true;
    }
};