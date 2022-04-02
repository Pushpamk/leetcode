class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] left = new int[n], right = new int[n];
        left[0] = right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            right[i] = nums[i + 1] * right[i + 1];
        
        int[] ans = new int[n];
        
        for (int i = 1; i <= n - 1; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        for (int i = 0; i <= n  - 1; i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
}
