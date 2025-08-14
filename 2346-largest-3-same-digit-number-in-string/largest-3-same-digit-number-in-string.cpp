class Solution {
public:
    string largestGoodInteger(string num) {
        int ans=-1;
        unordered_map<char,int> mp;
        int l=0;
        for (int i = 0; i < num.size(); i++) {
            mp[num[i]]++;
            while(mp.size()>=2)
            {
                if(--mp[num[l]]==0) mp.erase(num[l]);
                l++;
            }
            if(mp[num[i]]==3)
            {
                if(ans==-1 || (num[i]-'0')>ans)
                {
                    ans=num[i]-'0';
                }
            }
        }
        if(ans==-1) return "";
        return string(3,ans+'0');
    }
};