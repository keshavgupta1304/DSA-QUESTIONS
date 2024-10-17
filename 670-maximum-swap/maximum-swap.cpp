class Solution {
public:
    int maximumSwap(int num) {
        string number=to_string(num);
        int n=number.length();
        int pos=-1;
        for(int i=0;i<n;i++)
        {
            int maxDigit = 0;
            for(int j=n-1;j>i;j--)
            {
                if(((number[j]-'0')>(number[i]-'0')) && ((number[j]-'0')>(maxDigit)))
                {
                    maxDigit=number[j]-'0';
                    pos=j;
                }
            }
            if(pos!=-1)
            {
                swap(number[i],number[pos]);
                break;
            }
        }
        return stoi(number);
    }
};