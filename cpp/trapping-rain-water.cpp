class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        int lmax = 0, rmax = 0;
        while (left <= right) {
            if (height[left] < height[right]) {
                lmax < height[left] ? lmax = height[left] : ans += lmax - height[left];
                left++;
            }
            else {
                rmax < height[right] ? rmax = height[right] : ans += rmax - height[right];
                right--;
            }
        }
        return ans;
    }
};
