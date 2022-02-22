class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        int rot = left;
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            int realmid = (mid + rot) % nums.size();
            if (nums[realmid] == target)
                return realmid;
            
            if (nums[realmid] < target )
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
