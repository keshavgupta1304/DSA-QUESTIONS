class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<>> minHeap;
        vector<char> copy(s.begin(),s.end());

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*' && !minHeap.empty())
            {
                auto [deletedChar,negIndex]=minHeap.top();
                minHeap.pop();
                copy[i]='A';
                copy[-negIndex]='A';
            }
            else
            {
                minHeap.push({s[i],-i});
            }
        }
        string result;
        for(auto ch:copy)
        {
            if(ch!='A') result.push_back(ch);
        }
        return result;
    }
};