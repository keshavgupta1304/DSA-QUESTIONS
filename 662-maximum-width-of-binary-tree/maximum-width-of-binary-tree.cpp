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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int width=0;
        while(!q.empty())
        {
            int size=q.size();
            int minLevel=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                auto ele = q.front();
                q.pop();
                int curId=ele.second-minLevel;
                if(ele.first->left!=nullptr)
                {
                    q.push({ele.first->left,(long long)2*curId+1});
                }
                if(ele.first->right!=nullptr)
                {
                    q.push({ele.first->right,(long long)2*curId+2});
                }
                if(i==0)
                {
                    first=curId;
                }
                if(i==size-1)
                {
                    last=curId;
                }
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};