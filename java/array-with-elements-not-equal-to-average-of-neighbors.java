class Solution {
    public int[] rearrangeArray(int[] nums) {
        Arrays.sort(nums);
        int[] ans = new int[nums.length];
        int low = 0, high = nums.length - 1;
        int i = 0;
        while (i <= nums.length - 1) {
            ans[i] = nums[low];
            low++;
            i++;
            
            if (low < high) {
                ans[i] = nums[high];
                i++;
                high--;
            }
        }
        return ans;
    }
}
