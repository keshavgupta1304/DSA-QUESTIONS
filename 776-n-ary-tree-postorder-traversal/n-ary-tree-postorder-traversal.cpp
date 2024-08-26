/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if(root==nullptr)
        {
            return result;
        }
        traversePostOrder(root,result);
        return result;
    }
    void traversePostOrder(Node* currentNode,vector<int>& result)
    {
        if(currentNode==nullptr)
        {
            return;
        }
        //process all child nodes
        for(auto childrenNode : currentNode->children)
        {
            traversePostOrder(childrenNode,result);
        }

        // add the root value after all are explored
        result.push_back(currentNode->val);
    }
};