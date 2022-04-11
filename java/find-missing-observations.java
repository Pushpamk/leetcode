class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int sum1 = Arrays.stream(rolls).sum();
        int target = mean * (rolls.length + n) - sum1;
        if (target > n * 6 || target <= 0 || target < n)
            return new int[0];
        
        int[] ans = new int[n];
        int min = target / n;
        int counter = target % n;
        for (int i = 0; i < n; i++) {
            ans[i] = min;
            target -= min;
            if (counter != 0) {
                ans[i]++;
                --counter;
                target--;
            }
        }
        return ans;
    }
}
