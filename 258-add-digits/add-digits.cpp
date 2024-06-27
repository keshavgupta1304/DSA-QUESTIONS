class Solution {
public:
    int calculateSumOfDigits(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int addDigits(int num) {
        if(num<10)
        {
            return num;
        }
        int sum=calculateSumOfDigits(num);
        
        while(sum>=10)
        {
            sum=calculateSumOfDigits(sum);
        }
        return sum;
    }
};