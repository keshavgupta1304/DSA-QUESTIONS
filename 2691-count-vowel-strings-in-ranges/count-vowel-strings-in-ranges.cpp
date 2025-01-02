class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        else return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result;
        int n=words.size();
        vector<int> prefixSum(n,0);
        int i=0;
        for(auto word:words)
        {
            if(isVowel(word[0]) && isVowel(word[word.size()-1]))
            {
                prefixSum[i]=1;
            }
            if(i>0) prefixSum[i]=prefixSum[i]+prefixSum[i-1];
            i++;
        }
        for(auto query:queries)
        {
            if(query[0]==0) result.push_back(prefixSum[query[1]]);
            else
            {
                result.push_back(prefixSum[query[1]]-prefixSum[query[0]-1]);
            }
        }
        return result;
    }
};