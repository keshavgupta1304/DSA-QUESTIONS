class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=chalk[i];
            if(sum>k)
            {
                break;
            }
        }
        k=k%sum;
        for(int i=0;i<chalk.size();i++)
        {
            if(chalk[i]>k)
            {
                return i;
            }
            k=k-chalk[i];
        }
        return 0;
    }    
};