class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        vector<int> tmp; 
        dfs(graph, 0, ans, tmp); // dfs(graph, 0, ans, tmp)
        return ans;
    }
    // vector<int> tmp - pass by value
    void dfs(vector<vector<int>>& graph, int cur, vector<vector<int>>& ans, vector<int>& tmp) {
        tmp.push_back(cur);
        if (cur == graph.size() - 1) {
            ans.push_back(tmp);
            return;
        }
        
        for (auto cur_adj : graph[cur]) {
            dfs(graph, cur_adj, ans, tmp);
            tmp.pop_back(); // if we pass tmp by value then we don't have to pop
        }
        
    }
};
