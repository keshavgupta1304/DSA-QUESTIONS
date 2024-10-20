/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* temp=head;
        unordered_map<Node*,Node*> mp;
        mp.insert({nullptr,nullptr});
        while(temp)
        {
            Node* newNode=new Node(temp->val);
            mp.insert({temp,newNode});
            temp=temp->next;
        }
        temp=head;
        Node* result=mp[temp];
        while(temp)
        {
            Node* newNode=mp[temp];
            newNode->next=mp[temp->next];
            newNode->random=mp[temp->random];
            temp=temp->next;
        }
        return result;
        
    }
};