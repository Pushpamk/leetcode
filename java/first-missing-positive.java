class Solution {
    public int firstMissingPositive(int[] nums) {
        int i = 0, n = nums.length;
        // cyclic sort
        /* 
         * Either the answer will be between 1 to (n - 1) or n
         */
        while (i < n) {
            if (nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
            }
            else
                i++;
        }
        for (i = 0; i <= n - 1; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}
