class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};
