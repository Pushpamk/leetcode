class StockSpanner {
    private Deque<int[]> st;
    public StockSpanner() {
        st = new ArrayDeque<>();
    }
    
    public int next(int price) {
        int res = 1;
        while(!st.isEmpty() && price >= st.peek()[0])
           res += st.pop()[1];
        st.push(new int[]{price, res});
        return res;
        
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
