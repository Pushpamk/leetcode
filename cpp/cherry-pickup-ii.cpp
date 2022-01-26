class Solution {
public:
    int dp[79][79][79];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int c = grid[0].size();
        int ans = dfs(grid, 0, 0, c - 1);
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, int row, int r1c, int r2c) {
        if (row >= grid.size() || r1c < 0 || r1c >= grid[0].size() || r2c < 0 || r2c >= grid[0].size())
            return 0;
        
        // if (r1c < 0 || r1c >= grid[0].size() || r2c < 0 || r2c >= grid[0].size())
        //     return INT_MIN;
        
        if (dp[row][r1c][r2c] != -1)
            return dp[row][r1c][r2c];
        
        int curr = grid[row][r1c] + grid[row][r2c];
        if (r1c == r2c)
            curr -= grid[row][r1c];
        
        int ans = INT_MIN;
        // ans = max(ans, curr + dfs(grid, row + 1, r1c - 1, r2c - 1));
        // ans = max(ans, curr + dfs(grid, row + 1, r1c - 1, r2c));
        // ans = max(ans, curr + dfs(grid, row + 1, r1c - 1, r2c + 1));
        // ans = max(ans, curr + dfs(grid, row + 1, r1c, r2c - 1));
        // ans = max(ans, curr + dfs(grid, row + 1, r1c, r2c));
        // ans = max(ans, curr + dfs(grid, row + 1, r1c, r2c + 1));
        // ans = max(ans, curr + dfs(grid, row + 1, r1c + 1, r2c - 1));
        // ans = max(ans, curr + dfs(grid, row + 1, r1c + 1, r2c));
        // ans = max(ans, curr + dfs(grid, row + 1, r1c + 1, r2c + 1));
        
        // above 9 lines can be replaced with below code, as we are making permution of r1c & r2c
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                ans = max(ans, curr + dfs(grid, row + 1, r1c + i, r2c + j));
            }
        }
        return dp[row][r1c][r2c] = ans;
    }
};
