class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Deque<Integer> q = new ArrayDeque<>();
        int ans = 1;
        q.push(0);
        boolean[] visited = new boolean[rooms.size()];
        while (!q.isEmpty()) {
            int cur = q.poll();
            visited[cur] = true;
            for (int u : rooms.get(cur)) {
                if (!visited[u]) {
                    ans++;
                    if (ans == rooms.size())
                        return true;
                    q.push(u);
                }
            }
        }
        return false;
    }
}
