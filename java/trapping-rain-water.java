class Solution {
    public int trap(int[] height) {
        int left = 0, right = height.length - 1, ans = 0, lmax = 0, rmax = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (lmax < height[left]) 
                    lmax = height[left];
                else
                    ans += lmax - height[left];
                left++;
            }
            else {
                if (rmax < height[right]) 
                    rmax = height[right];
                else
                    ans += rmax - height[right];
                right--;
            }
        }
        return ans;
    }
}
