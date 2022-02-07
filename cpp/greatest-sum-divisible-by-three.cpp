class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;
        
        for (int i = 1; i <= nums.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][nums[i - 1] % 3] + nums[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][(nums[i - 1] + 1) % 3] + nums[i - 1]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][(nums[i - 1] + 2) % 3] + nums[i - 1]);
        }
        return dp[nums.size()][0];
    }
};
