class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        List<Integer> tmp = new ArrayList<>();
        Arrays.sort(nums);
        backtracking(nums, ans, visited, tmp);
        return ans;
    }
    public void backtracking(int[] nums, List<List<Integer>> ans, boolean[] visited, List<Integer> tmp) {
        if (tmp.size() == nums.length) {
            ans.add(new ArrayList<>(tmp)); // because tmp contains list of reference not value, so create new arraylist
            return;
        }
        
        for (int i = 0; i <= nums.length - 1; i++) {
            if (visited[i])
                continue;
            // eg. 1,2,2 for current iteration of length say 2, [1,2] making choices to consider next 2, if we have already 2 
            // so [1,2] will be same as last one so ignore.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            
            visited[i] = true;
            tmp.add(nums[i]);
            backtracking(nums, ans, visited, tmp);
            visited[i] = false;
            tmp.remove(tmp.size() - 1);
        }
    }
}
