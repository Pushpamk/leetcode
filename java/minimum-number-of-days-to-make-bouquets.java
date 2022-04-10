class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int high = Integer.MIN_VALUE, low = 1;
        for (int b : bloomDay) 
            high = Math.max(high, b);
        
        int s = high;
        high = high + 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (feasible(bloomDay, m, k, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low > s ? -1 : low;
    }
    public boolean feasible(int[] bloomDay, int m, int k, int day) {
        int flower = 0;
        int bouquet = 0;
        for (int b : bloomDay) {
            if (day >= b) {
                flower++;
                if (flower == k) {
                    bouquet++;
                    flower = 0;
                    if (bouquet >= m)
                        return true;
                }
            }
            else
                flower = 0;
        }
        return false;
    }
}
