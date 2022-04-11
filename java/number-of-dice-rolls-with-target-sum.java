class Solution {
    private int[][] dp = new int[31][1001];
    public int numRollsToTarget(int n, int k, int target) {
        int count = 0;
        if (n == 0 || target <= 0) 
            return target == n ? 1 : 0; // means if either one of is zero then if target is zero and n is  also zero that means we have 1 solution
        if (dp[n][target] != 0)
            return dp[n][target] - 1;
        for (int i = 1; i <= k; i++) {
            count = (count + numRollsToTarget(n - 1, k, target - i)) % 1000000007;
        }
        dp[n][target] = count + 1; // if count is zero still we will consider dp[n][target] this as calculated
        return count;
    }
}
