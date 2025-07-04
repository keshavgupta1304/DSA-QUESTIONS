class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int transform=0;
        int t;
        while (k != 1) {
            t=__lg(k);
            if((1LL<<t)==k) t--;
            k=k-(1LL<<t);
            transform+=operations[t];
        }
        char res='a'+(transform % 26);
        return res;
    }
};