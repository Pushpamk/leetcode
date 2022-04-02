class Solution {
    public int largestRectangleArea(int[] heights) {
        int[] left = LNG(heights);
        int[] right = RNG(heights);
        int ans = 0;
        for (int i = 0; i <= heights.length - 1; i++) {
            System.out.println(left[i] + ", " + right[i]);
            ans = Math.max(ans, Math.abs(left[i] - right[i] + 1) * heights[i]);
        }
        return ans;
    }
    
    
    public int[] LNG(int[] heights) {
        int n = heights.length;
        int[] left = new int[n];
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 0; i <= n - 1; i++) {
            while(!st.isEmpty() && heights[i] <= heights[st.peek()])
                st.pop();
            if (st.isEmpty())
                left[i] = -1;
            else {
                left[i] = st.peek();
            }
            st.push(i);
        }
        return left;
    }
    public int[] RNG(int[] heights) {
        int n = heights.length;
        int[] right = new int[n];
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; i--) {
            while(!st.isEmpty() && heights[i] <= heights[st.peek()])
                st.pop();
            if (st.isEmpty())
                right[i] = n;
            else
                right[i] = st.peek();
            st.push(i);
        }
        for (int i = 0; i <= n - 1; i++) {
            int tmp = right[i];
            right[i] = right[n - i - 1];
            right[n - i - 1] = tmp;
        }
        return right;
    }
}
