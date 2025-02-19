class Solution {
private:
    void recur(vector<string>& storeStrings,int n,string happyString,int index)
    {
        if(index>1 && happyString[index-1]==happyString[index-2]) return;
        if(index>=n)
        {
            storeStrings.push_back(happyString);
            return;
        }
        recur(storeStrings,n,happyString + 'a',index+1);
        recur(storeStrings,n,happyString + 'b',index+1);
        recur(storeStrings,n,happyString + 'c',index+1);
    }
public:
    string getHappyString(int n, int k) {
        string result="";
        if(n<7)
        {
            int noOfHappyStrings=3*(pow(2,n-1));
            if(k>noOfHappyStrings) return result;
        }
        vector<string> storeStrings;
        string happyString="";
        recur(storeStrings,n,happyString,0);
        return storeStrings[k-1];
    }
};