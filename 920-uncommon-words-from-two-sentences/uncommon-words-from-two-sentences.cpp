class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        unordered_map<string,int> string1;
        unordered_map<string,int> string2;
        int n=s1.length();
        int m=s2.length();
        int i=0;
        while(i<n)
        {
            string temp="";
            while(s1[i]!=' ' && i<n)
            {
                temp+=s1[i];
                i++;
            }
            i++;
            if(!temp.empty())
            {
                string1[temp]++;
            }
        }
        int j=0;
        while(j<m)
        {
            string temp="";
            while(s2[j]!=' ' && j<m)
            {
                temp+=s2[j];
                j++;
            }
            j++;
            if(!temp.empty())
            {
                string2[temp]++;
            }
        }
        for(auto word:string1)
        {
            if((word.second==1) && (string2.find(word.first)==string2.end()))
            {
                result.push_back(word.first);
            }
        }
        for(auto word:string2)
        {
            if((word.second==1) && (string1.find(word.first)==string1.end()))
            {
                result.push_back(word.first);
            }
        }
        
        return result;
    }
};