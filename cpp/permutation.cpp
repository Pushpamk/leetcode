class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> tmp;
        permutation(nums, ans, visited, tmp);
        return ans;
    }
    void permutation(vector<int>& nums, vector<vector<int>>& ans, vector<bool>& visited, vector<int> tmp) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i <= nums.size() - 1; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            tmp.push_back(nums[i]);
            permutation(nums, ans, visited, tmp);
            visited[i] = false;
            tmp.pop_back();
        }
    }
};
