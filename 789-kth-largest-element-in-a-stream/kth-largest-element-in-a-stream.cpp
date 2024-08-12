class KthLargest {
public:
    int k;
    vector<int> arr;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums)
        {
            arr.push_back(num);
        }
        sort(arr.begin(),arr.end());
    }
    int add(int val) {
        int insertIndex=getIndex(val);
        if(insertIndex>=arr.size())
        {
            arr.push_back(val);
        } 
        else
        {
            arr.insert(arr.begin()+insertIndex,val);
        } 
        return arr[arr.size()-k];
    }
    int getIndex(int value)
    {
        for(int i=0;i<arr.size();i++)
        {
            if(value<=arr[i])
            {
                return i;
            }
        }
        return arr.size();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */