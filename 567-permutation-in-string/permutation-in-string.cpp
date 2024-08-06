class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();

        if(n>m) return false;

        unordered_map<char,int> f_s1;
        unordered_map<char,int> f_s2;
        for(int i=0;i<n;i++)
        {
            f_s1[s1[i]]++;
            f_s2[s2[i]]++;
        }
        if(f_s1==f_s2)
        {
            return true;
        }
        for(int i=n;i<m;i++)
        {
            char chOut=s2[i-n];
            if(f_s2[chOut]==1)
            {
                f_s2.erase(chOut);
            }
            else
            {
                f_s2[chOut]--;
            }
            
            char chToInsert=s2[i];
            f_s2[chToInsert]++;
            if(f_s2==f_s1) return true;
        }
        return false;


    }
};