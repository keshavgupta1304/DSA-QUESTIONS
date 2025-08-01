/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        unordered_map<int, TreeNode*> nodeToPar;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    nodeToPar[node->left->val] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    nodeToPar[node->right->val] = node;
                }
            }
        }
        q.push(target);
        unordered_set<int> st;
        st.insert(target->val);
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            if (dist == k)
                break;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    if (st.find(node->left->val) == st.end()) {
                        st.insert(node->left->val);
                        q.push(node->left);
                    }
                }
                if (node->right) {
                    if (st.find(node->right->val) == st.end()) {
                        st.insert(node->right->val);
                        q.push(node->right);
                    }
                }
                if(nodeToPar.find(node->val)!=nodeToPar.end())
                {
                    TreeNode* parent=nodeToPar[node->val];
                    if(st.find(parent->val) == st.end())
                    {
                        st.insert(parent->val);
                        q.push(parent);
                    }
                }
            }
            dist++;
        }
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};