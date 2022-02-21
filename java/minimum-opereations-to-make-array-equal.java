class Solution {
    /**
     * Get the minum operations to make an array equal.
     * @param n     length of the array.
     * @return Minimum operations to make an array equal.
     */
    public int minOperations(int n) {
        int half = 0, ans = 0;
        if (n % 2 == 0)
            half = (n / 2) - 1;
        else
            half = (n / 2);
        
        for (int i = 0; i <= half; i++)
            ans += n - 1 - 2 * i;
        
        return ans;
    }
}
