class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, (i, j) -> Integer.compare(i[0], j[0]));
        ans.add(intervals[0]);
        for (int[] interval : intervals) {
            if (interval[0] <= ans.get(ans.size() - 1)[1]) {
                ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], interval[1]);
            } 
            else {
                ans.add(interval);
            }
        }
        return ans.toArray(new int[0][]);
    }
}
