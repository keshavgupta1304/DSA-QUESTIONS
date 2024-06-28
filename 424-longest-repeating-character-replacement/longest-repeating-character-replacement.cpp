class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //two pointers for window
        int left=0;
        int right=0;
        // for storing the freq of characters in a particular window
        vector<int> count(26);//26 alphabets are there

        int result=0;// size of window 
        int maxFreq=0;//maximum frequency of a charcater in a particular window

        while(right<s.length())
        {
            count[s[right]-'A']++;//increment the count

            maxFreq=max(maxFreq,count[s[right]-'A']);
            if(right-left+1 - maxFreq > k)
            {
                count[s[left]-'A']--;
                left++;
            }
            
            result=max(result,right-left+1);
            right++;
        }
        return result;

    }
};