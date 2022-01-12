class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxFar = 0, endWindow = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxFar = max(maxFar, i + nums[i]);
            if (i == endWindow)
                endWindow = maxFar;
        }
        return endWindow >= nums.size() - 1;
    }
};
