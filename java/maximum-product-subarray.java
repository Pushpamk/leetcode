class Solution {
    public int maxProduct(int[] nums) {
        int lproduct = 1, rproduct = 1, max_product = Integer.MIN_VALUE;
        for (int i = 0; i <= nums.length - 1; i++) {
            lproduct = (lproduct == 0 ? 1 : lproduct) * nums[i];
            rproduct = (rproduct == 0 ? 1 : rproduct) * nums[nums.length - 1 - i];
            max_product = Math.max(max_product, Math.max(lproduct, rproduct));
        }
        return max_product;
    }
}
