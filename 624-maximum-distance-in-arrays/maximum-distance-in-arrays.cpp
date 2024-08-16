class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0][0];
        int max_val = arrays[0].back();
        int maximum_distance = 0;
        
        for (int i = 1; i < arrays.size(); ++i) {
            int cur_min = arrays[i][0];
            int cur_max = arrays[i].back();
            
            // Calculate the possible distances
            maximum_distance = max(maximum_distance, abs(cur_max - min_val));
            maximum_distance = max(maximum_distance, abs(cur_min - max_val));
            
            // Update global min and max
            min_val = min(min_val, cur_min);
            max_val = max(max_val, cur_max);
        }
        
        return maximum_distance;
    
    }
};