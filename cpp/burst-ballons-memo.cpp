class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2; // to add 1 for handling out of bound
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> new_nums(n, 1);
        
        int i = 1;
        for (int x : nums)
            new_nums[++i] = x; // filling new vector with original nums and leaving 1 end the beginning and ending
        
        solve(new_nums, 0, new_nums.size() - 1, dp);
        
        return dp[0][new_nums.size() - 1];
    }
    
private: 
    
    int solve(vector<int> &nums, int i, int j, vector<vector<int>>& dp) {
        if (i + 1 >= j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        for (int k = i + 1; k < j; k++) {
            dp[i][j] = max(dp[i][j], solve(nums, i, k, dp) + solve(nums, k, j, dp) + nums[i] * nums[k] * nums[j]);
        }
        return dp[i][j];
    }
};
