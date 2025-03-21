class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> supply(supplies.begin(),supplies.end());
        queue<int> q;
        for(int i=0;i<recipes.size();i++) q.push(i);
        int lastSize=-1;
        while(static_cast<int>(supply.size())>lastSize)
        {
            lastSize=supply.size();
            int queueSize=q.size();
            while(queueSize>0)
            {
                int index=q.front();
                q.pop();
                bool isPossible=true;
                for(int i=0;i<ingredients[index].size();i++)
                {
                    if(supply.find(ingredients[index][i])==supply.end())
                    {
                        isPossible=false;
                        break;
                    }
                }
                if(isPossible)
                {
                    supply.insert(recipes[index]);
                    ans.push_back(recipes[index]);
                }
                else
                {
                    q.push(index);
                }
                queueSize--;
            }
        }
        return ans;
    }
};