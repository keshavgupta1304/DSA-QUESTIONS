class Solution {
private:
    bool recur(string& result,int n,set<string> binaryStr,int index)
    {
        if(index>=n)
        {
            if(binaryStr.find(result)==binaryStr.end())
            {
                return true;
            }
            return false;
        }
        result=result+'0';
        if(recur(result,n,binaryStr,index+1)) return true;
        result.pop_back();
        result=result+'1';
        if(recur(result,n,binaryStr,index+1)) return true;
        result.pop_back();
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result="";
        int n=nums.size();
        set<string> binaryStr(nums.begin(),nums.end());
        recur(result,n,binaryStr,0);
        return result;
    }
};