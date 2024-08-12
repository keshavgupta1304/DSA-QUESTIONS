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
    int getIndex(int val)
    {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midValue = arr[mid];
            if (midValue == val) return mid;
            if (midValue > val) {
                // Go to left half
                right = mid - 1;
            } else {
                // Go to right half
                left = mid + 1;
            }
        }
        return left;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */