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
    TreeNode* recur(int preStart,int preEnd,int postStart,const vector<int> preorder, const vector<int> postorder)
    {
        if(preStart>preEnd) return nullptr;
        if(preStart==preEnd) return new TreeNode(preorder[preStart]);
        TreeNode* root=new TreeNode(preorder[preStart]);
        int leftRoot=preorder[preStart+1];
        int numNodesInLeft=0;
        while(postorder[postStart+numNodesInLeft]!=leftRoot)
        {
            numNodesInLeft++;
        }
        root->left=recur(preStart+1,preStart+numNodesInLeft+1,postStart,preorder,postorder);
        root->right=recur(preStart+numNodesInLeft+2,preEnd,postStart+numNodesInLeft+1,preorder,postorder);
        return root;

    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int numNodes=preorder.size();
        return recur(0,numNodes-1,0,preorder,postorder);
    }

};