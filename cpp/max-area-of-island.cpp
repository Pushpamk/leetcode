class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i <= m - 1; i++) {
            for (int j = 0; j <= n - 1; j++) {
                if (grid[i][j] == 1) {
                    int tmp = dfs(grid, i, j);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if ((i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) || grid[i][j] != 1)
            return 0;
        grid[i][j] = 2;
        int tmp = 1;
        tmp += dfs(grid, i - 1, j);
        tmp += dfs(grid, i + 1, j);
        tmp += dfs(grid, i, j - 1);
        tmp += dfs(grid, i, j + 1);
        return tmp;
    }
};
