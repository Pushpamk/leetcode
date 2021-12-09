class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for( int n : nums) {
            if (n != val) {
                nums[i] = n;
                i++;
            }
        }
        return i;
    }
};
