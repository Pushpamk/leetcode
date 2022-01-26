class Solution {
public:
    int jump(vector<int>& nums) {
        int maxFar = 0, jumps = 0, endWindow = 0;
        for (int i = 0; i < nums.size() - 1; i++) { //nums.size() - 1 because we are already standing at 1st i.e 0 index
            maxFar = max(maxFar, i + nums[i]); // calculate farthest point we can jump from current index
            if (i == endWindow) {
                jumps++;
                endWindow = maxFar;
            }
        }
        return jumps;
    }
};
