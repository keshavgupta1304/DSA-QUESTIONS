class Solution {
public:
    bool generateIndexes(const vector<int>& groups,int groupNo,int index,vector<int>& indexes)
    {
        if(index==groups.size())
        {
            return true;
        }
        //pick the element
        if(groups[index]!=groupNo)
        {
            indexes.push_back(index);
            if(generateIndexes(groups,groups[index],index+1,indexes)) return true;
            indexes.pop_back();
        }
        //do not pick the element
        if(generateIndexes(groups,groupNo,index+1,indexes)) return true;
        return false;
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> indexes;
        generateIndexes(groups,-1,0,indexes);
        vector<string> result;
        for(auto index:indexes)
        {
            result.push_back(words[index]);
        }
        return result;
    }
};