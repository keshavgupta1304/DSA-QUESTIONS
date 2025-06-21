class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n=word.size();
        if(n==0) return 0;
        vector<int> count(26,0);
        for(auto ch:word){
            count[ch-'a']++;
        }
        sort(count.begin(),count.end());
        int deletions=INT_MAX;
        int l=0;
        while(count[l]==0) l++;

        for(int i=l;i<26;i++)
        {
            int range=count[i]+k;
            int total=count[i];
            for(int j=i+1;j<26;j++)
            {
                if(count[j]<=range) total+=count[j];
                else total+=range;
            }
            deletions=min(deletions,n-total);
        }
        return deletions;
    }
};