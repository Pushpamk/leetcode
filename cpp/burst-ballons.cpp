// MCM problem
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2; // to add 1 for handling out of bound
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> new_nums(n, 1);
        int i = 1;
        for (int x : nums)
            new_nums[++i] = x; // filling new vector with original nums and leaving 1 end the beginning and ending
        
        for (int t = 2; t <= n; t++ ) {
            for (int i = 0; i <= n - t; i++) {
                int j = i + t - 1;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + new_nums[i] * new_nums[k] * new_nums[j]);
            }
        }
        return dp[0][n - 1];
    }
};
