class Solution {
    public int minOperations(int[] nums1, int[] nums2) {
        if (nums1.length * 6 < nums2.length || nums2.length * 6 < nums1.length)
            return -1;
        int s1 = 0, s2 = 0;
        
        for (int n1 : nums1)
            s1 += n1;
        
        for (int n2 : nums2)
            s2 += n2;
        
        if (s1 < s2) {
            return helper(nums1, nums2, s1, s2);
        }
        return helper(nums2, nums1, s2, s1);
    }
    
    public int helper(int[] nums1, int[] nums2, int s1, int s2) {
        int[] count = new int[6];
        int diff = Math.abs(s1 - s2);
        int ops = 0;
        for (int n1 : nums1) 
            ++count[6 - n1];
        for (int n2: nums2) 
            ++count[n2 - 1];
        
        for (int i = 5; i > 0 && diff > 0; --i) {
            int modification = Math.min(count[i], diff/i + (diff % i == 0 ? 0 : 1));
            diff -= i * modification;
            ops += modification;
        }
        return ops;
    }
}
