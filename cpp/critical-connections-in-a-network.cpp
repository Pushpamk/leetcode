class Solution {
public:
    void dfs(int curNode, int parent, vector<vector<int>>& g, vector<bool>& vi, vector<int>& tin, vector<int>& low, int& timer, vector<vector<int>>& ans) {
        tin[curNode] = timer++;
        low[curNode] = tin[curNode];
        vi[curNode] = true;
        for (auto& neigh : g[curNode]) {
            if (neigh == parent)
                continue;
            if (!vi[neigh]) {
                // vi[neigh] = true;
                
                dfs(neigh, curNode, g, vi, tin, low, timer, ans);
                
                low[curNode] = min(low[curNode], low[neigh]);
                if (tin[curNode] < low[neigh])
                    ans.push_back({curNode, neigh});
            }
            else
                low[curNode] = min(low[curNode], tin[neigh]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<bool> vi(n, false);
        vector<vector<int>> ans;
        
        for (auto& c : connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        
        int timer = 0;
        
        for (int i = 0; i <= n - 1; i++) {
            if (!vi[i]) {
                dfs(i, -1, g, vi, tin, low, timer, ans);
            }
        }
        return ans;
    }
};
