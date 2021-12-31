class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), ans;
        
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) { // because it is directed both side other wise indegree[i] == 0 should work
                indegree[i]--;
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            ans.clear(); // clear last layer nodes
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int v = q.front();
                q.pop();
                ans.push_back(v);
                for ( auto u : adj[v]) {
                    indegree[u]--;
                    if (indegree[u] == 1)
                        q.push(u);
                }
            }
        }
        
        return ans;
        
    }
};
