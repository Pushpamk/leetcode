class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> sorted(high - low + 1);
        
        int i = low, j = mid + 1, k = 0;
        
        while (i <= mid && j <= high) {
            if (nums[i] < nums[j]) {
                sorted[k] = nums[i];
                i++;
            } 
            else {
                sorted[k] = nums[j];
                j++;
            }
            k++;
        }
        while (i <= mid)
            sorted[k++] = nums[i++];
        while (j <= high)
            sorted[k++] = nums[j++];
        
        for (int i = 0; i <= k - 1; i++)
            nums[low + i] = sorted[i];
    }
};
