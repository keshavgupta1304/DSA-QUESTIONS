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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<pair<int,int>,vector<int>> mp;
        queue<tuple<TreeNode*, int, int>> q;         
        q.emplace(root, 0, 0);
        while (!q.empty()) {
            auto [node, x, y] = q.front(); q.pop();
            mp[{y, x}].push_back(node->val);     
            if (node->left)  q.emplace(node->left,  x+1, y-1);
            if (node->right) q.emplace(node->right, x+1, y+1);
        }
        for(auto &[coord,vec]:mp)
        {
            sort(vec.begin(),vec.end());
        }
        vector<vector<int>> result;
        int y=INT_MIN;
        vector<int> temp;
        for(auto [coord,values]:mp)
        {
            int size=values.size();
            if(y!=INT_MIN && y==coord.first)
            {
                for(int i=0;i<size;i++)
                {
                    temp.push_back(values[i]);
                }
            }
            else if(y!=coord.first || y==INT_MIN)
            {
                y=coord.first;
                if(!temp.empty()) result.push_back(temp);
                temp={};
                for(int i=0;i<size;i++)
                {
                    temp.push_back(values[i]);
                }
            }
        }
        if(!temp.empty()) result.push_back(temp);
        return result;
    }
};