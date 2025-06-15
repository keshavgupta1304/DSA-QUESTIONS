class TreeAncestor {
    vector<vector<int>> up;
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while ((1 << LOG) <= n) {
            LOG++;
        }
        up = vector<vector<int>>(n, vector<int>(LOG, -1));
        for (int v = 0; v < n; v++) {
            up[v][0] = parent[v];
        }
        for (int j = 1; j < LOG; j++) {
            for (int v = 0; v < n; v++) {
                int mid = up[v][j - 1];
                up[v][j] = (mid == -1 ? -1 : up[mid][j - 1]);
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for (int j = LOG - 1; j >= 0 && node != -1; j--) {
            if (k >= (1 << j)) {
                node = up[node][j];
                k -= 1 << j;
            }
        }
        return node;
    }
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */