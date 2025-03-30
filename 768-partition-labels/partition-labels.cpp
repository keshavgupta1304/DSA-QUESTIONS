class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> visited(26,-1);
        int n=s.size();
        vector<int> result;
        vector<int> lastIndex(26,-1);
        for(int i=0;i<n;i++)
        {
            lastIndex[s[i]-'a']=i;
        }
        int maxi=INT_MIN;
        int lastPartitionIndex=-1;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,lastIndex[s[i]-'a']);
            if(i==maxi)
            {
                if(lastPartitionIndex==-1)
                {
                    result.push_back(i+1);
                } 
                else
                {
                    result.push_back(i-lastPartitionIndex);
                }
                lastPartitionIndex=i;
                maxi=INT_MIN;
            }
        }
        return result;
    }
};