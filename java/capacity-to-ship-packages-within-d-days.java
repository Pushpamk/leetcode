class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int low = Integer.MIN_VALUE;
        int high = 0;
        for (int w : weights) {
            low = Math.max(low, w);
            high += w;
        }
        
        while (low < high) {
            int mid = low + (high - low)/2;
            if (feasible(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
        
    }
    
    public boolean feasible(int[] weights, int days, int capacity) {
        int d = 1;
        int total = 0;
        for (int w : weights) {
            total += w;
            if (total > capacity) {
                total = w;
                d++;
                if (d > days)
                    return false;
            }
        }
        return true;
    }
}
