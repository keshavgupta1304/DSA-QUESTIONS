class Node{
public:
    Node* links[2];
    Node(){
        links[0]=nullptr;
        links[1]=nullptr;
    }
    bool containsKey(int bit){
        return (links[bit]!=nullptr);
    }
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
private: 
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
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num,int limit)
    {
        int mx=0;
        Node* node=root;
        if(!node->containsKey(0) && !node->containsKey(1)) return -1;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(!bit))
            {
                mx=mx|(1<<i);
                node=node->get(!bit);
            }
            else
            {
                node=node->get(bit);
            }
        }
        return mx;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n=queries.size();
        vector<tuple<int,int,int>> q;
        for(int i=0;i<n;i++){
            q.emplace_back(queries[i][1],queries[i][0],i);
        }
        sort(q.begin(),q.end());
        vector<int> ans(n);
        Trie trie;
        int i=0;
        for(auto &ele:q)
        {
            int x=get<1>(ele);
            int m=get<0>(ele);
            int index=get<2>(ele);
            while(i<int(nums.size()) && nums[i]<=m){
                trie.insert(nums[i]);
                i++;
            }
            int mx=trie.getMax(x,m);
            ans[index]=mx;
        }
        return ans;
    }
};