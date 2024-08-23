class Solution {
public:
    string fractionAddition(string expression) {
        int num=0;
        int deno=1;

        int i=0;
        while(i<expression.size())
        {
            int currNum=0;
            int currDeno=0;

            bool isNegative=false;
            if(expression[i]=='-' || expression[i]=='+')
            {
                if(expression[i]=='-') isNegative=true;
                i++;
            }
            //build the numerator
            while(isdigit(expression[i]))
            {
                int value = expression[i]-'0';
                currNum = currNum * 10 + value;
                i++;
            }
            if(isNegative) currNum*=-1;
            i++;//skip the divide part
            while(i<expression.size() && isdigit(expression[i]))
            {
                int value = expression[i] - '0';
                currDeno = currDeno * 10 + value;
                i++;
            }
            num = num*currDeno + currNum*deno;
            deno = deno * currDeno;
        }
        int GCD = abs(gcd(num,deno));
        num/=GCD;
        deno/=GCD;
        return to_string(num)+"/"+to_string(deno);
    }
    int gcd(int a,int b)
    {
        if(a==0) return b;
        return gcd(b%a,a);
    }
};