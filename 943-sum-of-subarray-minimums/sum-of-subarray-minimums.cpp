class Solution {
private:
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
public:
    const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int total=0;
        int n=arr.size();
        vector<int> nse(n,n);
        vector<int> psee(n,-1);
        findNse(nse,arr);
        findPsee(psee,arr);
        for(int i=0;i<n;i++)
        {
            int left=i-psee[i];
            int right=nse[i]-i;
            total=(total+(right*left*1LL*arr[i])%MOD)%MOD;
        }
        return total;
    }
};