class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;// a map to store the number and its occurence
        for(auto x:arr)
        {
            mp[x]++; // increase the count of the element which is repeated in arr
        }
        vector<int> v; // vector to store the no of occurences of the elements
        for(auto x: mp)
        {
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());

        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1]) return false;//check if occurences are same or not
        }
        return true;
    }
};