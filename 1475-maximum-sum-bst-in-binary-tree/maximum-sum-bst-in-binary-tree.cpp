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
class NodeValue{
public:
    int minNode;int maxNode;int sum;
    NodeValue(int minNode,int maxNode,int sum)
    {
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->sum=sum;
    }
};
class Solution {
public:
    int maxSum;
    NodeValue helper(TreeNode* root)
    {
        if(!root)
        {
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        auto l=helper(root->left);
        auto r=helper(root->right);
        if(l.maxNode<root->val && root->val<r.minNode)
        {
            maxSum=max(maxSum,l.sum+r.sum+root->val);
            return NodeValue(min(root->val,l.minNode),max(r.maxNode,root->val),l.sum+r.sum+root->val);
        }
        return NodeValue(INT_MIN,INT_MAX,0);
    }
    int maxSumBST(TreeNode* root) {
        maxSum=INT_MIN;
        helper(root).sum;
        return max(0,maxSum);
    }
};