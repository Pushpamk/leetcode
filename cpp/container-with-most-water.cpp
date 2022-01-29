class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            area = max(area, min(height[right], height[left]) * (right - left));
            height[right] > height[left] ? left++ : right--;
        }
        return area;
    }
};
