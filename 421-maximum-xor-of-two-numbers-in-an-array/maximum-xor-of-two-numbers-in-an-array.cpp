class Node{
    public:
    Node* links[2];
    Node(){
        links[0]=nullptr;
        links[1]=nullptr;
    }
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit)
    {
        return links[bit];
    }

};
class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(int num)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }   
    int getMax(int num)
    {
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(!bit))
            {
                maxNum+=(1<<i);
                node=node->get(!bit);
            }
            else
            {
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &num:nums) trie.insert(num);
        int mx=0;
        for(auto num:nums)
        {
            mx=max(mx,trie.getMax(num));
        }
        return mx;
    }
};