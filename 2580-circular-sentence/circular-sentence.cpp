class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.length();
        int i=0;
        bool ans=true;
        while(i<n)
        {
            while(sentence[i]!=' ' && i<n) i++;
            if(i==n)
            {
                if(sentence[i-1]!=sentence[0]) ans=false;
            }
            else
            {
                if(sentence[i-1]!=sentence[i+1])
                {
                    ans=false;
                    break;
                }
                i++;
            }
        }
        return ans;
    }
};