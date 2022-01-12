class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0, i = 0;
        for (; i < n && i <= reach; ++i) // basically the element we are looking are within the reach I already have because we are trying to find max reach till current element   
            reach = max(i + nums[i], reach);
        return reach >= n - 1;
    }
};
