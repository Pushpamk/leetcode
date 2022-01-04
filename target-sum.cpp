class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        for (int i : nums)
            sum += i;
        
        if (sum < target || (target + sum) & 1)
            return 0;
        
        target = (sum + target) / 2;
        
        if (target < 0)
            return 0;
        
        int dp[nums.size() + 1][target + 1];
        
        for (int i = 0; i < target + 1; i++)
            dp[0][i] = 0;
        
        for (int i = 0; i < nums.size() + 1; i++)
            dp[i][0] = 1;
        
        for (int i = 1; i < nums.size() + 1; i++) {
            for (int j = 0; j < target + 1; j++) { // starting from zero, because we are considering elements with zero value
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[nums.size()][target];
    }
};
