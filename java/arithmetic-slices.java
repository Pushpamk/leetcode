class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int ans = 0, cur = 0;
        for (int i = 0; i <= nums.length - 3; i++) {
            if (nums[i] - nums[i + 1] == nums[i + 1] - nums[i + 2]) {
                ++cur;
                ans += cur;
            }
            else 
                cur = 0;
        }
        return ans;
    }
}
