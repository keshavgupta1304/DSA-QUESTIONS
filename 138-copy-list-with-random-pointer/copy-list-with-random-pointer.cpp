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
        while(temp)
        {
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp)
        {
            Node* copyNode=temp->next;
            copyNode->random=(temp->random)?temp->random->next:nullptr;
            temp=temp->next->next;
        }
        Node* dummy=new Node(-1);
        Node* mover=dummy;
        temp=head;
        while(temp)
        {
            mover->next=temp->next;
            temp->next=temp->next->next;
            mover=mover->next;
            temp=temp?temp->next:nullptr;
        }
        return dummy->next;
    }
};