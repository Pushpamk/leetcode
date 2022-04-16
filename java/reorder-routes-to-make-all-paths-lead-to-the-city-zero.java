class Solution {
    public int minReorder(int n, int[][] connections) {
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i <= n - 1; i++)
            g.add(new ArrayList<>());
        for (int[] c : connections) {
            g.get(c[0]).add(c[1]);
            g.get(c[1]).add(-c[0]);
        }
        Deque<Integer> q = new ArrayDeque<>();
        int ans = 0;
        boolean[] visited = new boolean[n];
        q.push(0);
        while (!q.isEmpty()) {
            int cur = q.poll();
            visited[cur] = true;
            for (int u : g.get(Math.abs(cur))) {
                if (!visited[Math.abs(u)]) {
                    ans += u > 0 ? 1 : 0;
                    q.push(Math.abs(u));
                }
            }
        }
        return ans;
    }
}
