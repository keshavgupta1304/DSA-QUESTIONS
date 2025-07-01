class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        char ch=' ';
        int freq=0;
        for(int i=0;i<word.size();i++)
        {
            if(ch==' ' || word[i]!=ch)
            {
                ch=word[i];
                ans+=freq>1?freq-1:0;
                freq=1;
            }
            else if(word[i]==ch)
            {
                freq++;
            }
        }
        ans+=freq>1?freq-1:0;
        return ans;
    }
};