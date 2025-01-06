class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_map<int,vector<int>> mp;
        int n=boxes.size();
        for(int i=0;i<n;i++)
        {
            int digit = boxes[i] - '0';
            if(digit==1) mp[digit].push_back(i);
        }
        vector<int> result(n,0);
        for(int i=0;i<n;i++)
        {
            for(int index:mp[1])
            {
                result[i]+=abs(i-index);
            }
        }
        return result;
    }
};