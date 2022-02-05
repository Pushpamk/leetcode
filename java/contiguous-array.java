class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        hash.put(0, -1);
        int count = 0, maxLen = 0;
        for (int i = 0; i <= nums.length - 1; i++) {
            count += nums[i] == 1? 1 : -1;
            if (hash.containsKey(count))
                maxLen = Math.max(maxLen, i - hash.get(count));
            else
                hash.put(count, i);
        }
        return maxLen;
    }
}
