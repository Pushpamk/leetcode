class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, cur = 0;
        if (nums.size() < 3)
            return 0;
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (nums[i] - nums[i + 1] == nums[i + 1] - nums[i + 2]) {
                cur++;
                ans += cur;
            }
            else {
                cur = 0;
            }
        }
        return ans;
    }
};
