class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Deque<Integer> st = new ArrayDeque<>();
        int n = temperatures.length;
        int[] ans = new int[n];
        
        for (int i = n - 1; i >= 0; i--) {
            
            while (!st.isEmpty() && temperatures[i] >= temperatures[st.peek()])
                st.pop();
            
            // if (st.isEmpty())
            //     ans[i] = 0;
            if (!st.isEmpty()) {
                int greater_temp = st.peek();
                ans[i] = greater_temp - i;
            }
            st.push(i);
        }
        return ans;
    }
}
