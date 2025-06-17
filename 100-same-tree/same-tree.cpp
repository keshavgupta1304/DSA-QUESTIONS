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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        else if ((p!=nullptr && q==nullptr) || (p==nullptr && q!=nullptr)) return false;
        bool isLeft=isSameTree(p->left,q->left);
        if(!isLeft) return false;
        bool isRight=isSameTree(p->right,q->right);
        if(!isRight) return false;
        return p->val==q->val;
    }
};