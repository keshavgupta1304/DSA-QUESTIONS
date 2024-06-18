class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        int res=0;int prof=0;int j=0;
        vector<pair<int ,int >> temp;
        for(int i=0;i<worker.size();i++)
        {
            temp.push_back({difficulty[i],profit[i]});
        }
        sort(temp.begin(),temp.end());
        sort(worker.begin(),worker.end());
        for(int work:worker)
        {
            while(work>=temp[j].first && j<worker.size())
            {
                prof=max(prof,temp[j++].second);
            }

            res+=prof;
        }
        return res;
    }
};