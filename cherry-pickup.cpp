class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
        int ans;
        ans = dfs(grid, 0, 0, 0, 0, dp);
        return max(0, ans);
    }
    
private: 
    
    int dfs(vector<vector<int>>& grid, int r1, int r2, int rc1, int rc2, vector<vector<vector<vector<int>>>>& dp) {
        if (r1 >= grid.size() || r2 >= grid.size() || rc1 >= grid[0].size() || rc2 >= grid[0].size() || grid[r1][rc1] == -1 || grid[r2][rc2] == -1)
            return INT_MIN;
        
        if (dp[r1][rc1][r2][rc2] != -1)
            return dp[r1][rc1][r2][rc2];
        
        if (r1 == grid.size() - 1 && rc1 == grid[0].size() - 1)
            return grid[r1][rc1];
        
        if (r2 == grid.size() - 1 && rc2 == grid[0].size() - 1)
            return grid[r2][rc2];
        
        int curr = grid[r1][rc1] + grid[r2][rc2];
        if (r1 == r2 && rc1 == rc2)
            curr -= grid[r1][rc1];
        
        int ans = INT_MIN;
        ans = max(ans, dfs(grid, r1 + 1, r2 + 1, rc1, rc2, dp)); // down - down
        ans = max(ans, dfs(grid, r1 + 1, r2, rc1, rc2 + 1, dp)); // down - right
        ans = max(ans, dfs(grid, r1, r2 + 1, rc1 + 1, rc2, dp)); // right - down
        ans = max(ans, dfs(grid, r1, r2, rc1 + 1, rc2 + 1, dp)); // right - right
        
        return dp[r1][rc1][r2][rc2] = ans + curr;
    }
};
