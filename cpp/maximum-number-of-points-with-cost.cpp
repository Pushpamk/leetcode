class Solution {
public:
    /**
     * Get maximum number of points with cost in a grid.
     * @param points    The grid in which each cell consist of points
     * @return The number of points with cost
     */
    long long maxPoints(vector<vector<int>>& points) {
        long long n = points.size(), m = points[0].size();
        vector<long long> pre(m);
        for(int i = 0; i <= m - 1; i++)
            pre[i] = points[0][i];
        
        for(int i = 0; i <= n - 2; i++) {
            vector<long long> cur(m, 0), left(m, 0), right(m, 0);
            left[0] = pre[0];
            right[m - 1] = pre[m - 1];
            
            for (int j = 1; j <= m - 1; j++) {
                left[j] = max(left[j - 1] - 1, pre[j]);
            }
            
            for (int j = m - 2; j >= 0; j--)
                right[j] = max(right[j + 1] - 1, pre[j]);
            
            for (int j = 0; j <= m - 1; j++)
                cur[j] = points[i + 1][j] + max(left[j], right[j]);
            
            pre = cur;
        }
        
        long long ans = pre[0];
        for(int i = 1; i <= m - 1; i++)
            ans = max(ans, pre[i]);

        return ans;
        
    }
};
