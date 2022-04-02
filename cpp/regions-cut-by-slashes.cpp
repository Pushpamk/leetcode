class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>> g(grid.size() * 3, vector<int>(grid[0].size() * 3, 0));
        int ans = 0;
        for (int i = 0; i <= grid.size() - 1; ++i) {
            for (int j = 0; j <= grid[0].size() - 1; ++j) {
                if (grid[i][j] == '/') {
                    g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
                }
                else if (grid[i][j] == '\\')
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
        for (int i = 0; i <= g.size() - 1; ++i) {
            for (int j = 0; j <= g[0].size() - 1; ++j) {
                if (g[i][j] == 0) {
                    dfs(i, j, g);
                    ans++;
                }
                    
            }
        }
        return ans;
    }
    void dfs(int i, int j, vector<vector<int>>& g) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] != 0)
            return;
        g[i][j] = 1;
        dfs(i, j + 1, g), dfs(i, j - 1, g), dfs(i + 1, j, g), dfs(i - 1, j, g);
    }
};
