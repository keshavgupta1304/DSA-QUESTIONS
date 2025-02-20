class Solution {
private:
    void findNge(vector<int>& nge,vector<int> arr)
    {
        stack<int> indices;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!indices.empty() && arr[i]>=arr[indices.top()])
            {
                indices.pop();
            }
            if(!indices.empty()) nge[i]=indices.top();
            indices.push(i);
        }
    }
    void findPgee(vector<int>& pgee,vector<int> arr)
    {
        stack<int> indices;
        for(int i=0;i<arr.size();i++)
        {
            while(!indices.empty() && arr[i]>arr[indices.top()])
            {
                indices.pop();
            }
            if(!indices.empty()) pgee[i]=indices.top();
            indices.push(i);
        }
    }
    long long sumSubarrayMax(vector<int> arr)
    {
        long long total=0;
        int n=arr.size();
        vector<int> nge(n,n);
        vector<int> pgee(n,-1);
        findNge(nge,arr);
        findPgee(pgee,arr);
        for(int i=0;i<n;i++)
        {
            int left=i-pgee[i];
            int right=nge[i]-i;
            total=(total+(right*left*1LL*arr[i]));
        }
        return total;
    }
    void findNse(vector<int>& nse,vector<int> arr)
    {
        stack<int> indices;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!indices.empty() && arr[i]<=arr[indices.top()])
            {
                indices.pop();
            }
            if(!indices.empty()) nse[i]=indices.top();
            indices.push(i);
        }
    }
    void findPsee(vector<int>& psee,vector<int> arr)
    {
        stack<int> indices;
        for(int i=0;i<arr.size();i++)
        {
            while(!indices.empty() && arr[i]<arr[indices.top()])
            {
                indices.pop();
            }
            if(!indices.empty()) psee[i]=indices.top();
            indices.push(i);
        }
    }
    long long sumSubarrayMin(vector<int> arr)
    {
        long long total=0;
        int n=arr.size();
        vector<int> nse(n,n);
        vector<int> psee(n,-1);
        findNse(nse,arr);
        findPsee(psee,arr);
        for(int i=0;i<n;i++)
        {
            int left=i-psee[i];
            int right=nse[i]-i;
            total=(total+(right*left*1LL*arr[i]));
        }
        return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)-sumSubarrayMin(nums);
    }
};