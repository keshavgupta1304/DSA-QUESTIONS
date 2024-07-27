class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        map<long long,vector<pair<long long,long long>>> adjacencyList;
        for(int i=0;i<original.size();i++)
        {
            long long originalChar=original[i]-'a';
            long long changedChar=changed[i]-'a';
            long long costOfConversion=cost[i];
            adjacencyList[originalChar].push_back(make_pair(changedChar,costOfConversion));
        }
        vector<vector<long long>> shortestCostMatrix(26,vector<long long>(26,INT_MAX));
        for(auto& val:adjacencyList)
        {
            djakstra(val.first,shortestCostMatrix[val.first],adjacencyList);
        }
        int i=0;
        long long ans=0;
        for(int i=0;i<source.size();i++)
        {
            if(source[i]==target[i])
            {
                continue;
            }
            if(shortestCostMatrix[source[i]-'a'][target[i]-'a']==INT_MAX)
            {
                return -1;
            }
            ans=ans+shortestCostMatrix[source[i]-'a'][target[i]-'a'];
        }
        return ans==0?-1:ans;
    }
    void djakstra(long long source,vector<long long>& shortestCostPath,map<long long,vector<pair<long long,long long>>>& adjacencyList)
    {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            priorityQueue;
        priorityQueue.emplace(0,source);
        fill(shortestCostPath.begin(),shortestCostPath.end(),INT_MAX);
        shortestCostPath[source]=0;
        while(!priorityQueue.empty())
        {
            auto [currentCost,currentChar]=priorityQueue.top();
            priorityQueue.pop();
            if(currentCost>shortestCostPath[currentChar])
            {
                continue;
            }
            for(const auto& [neighbourChar,cost]:adjacencyList[currentChar])
            {
                if(shortestCostPath[neighbourChar]>currentCost+cost)
                {
                    shortestCostPath[neighbourChar]=currentCost+cost;
                    priorityQueue.emplace(shortestCostPath[neighbourChar],neighbourChar);
                }
            }
        }

    }
};