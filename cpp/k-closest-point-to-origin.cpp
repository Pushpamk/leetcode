class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> ecd;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i <= points.size() - 1; i++) {
            ecd.push_back({(points[i][0] * points[i][0]) + (points[i][1] * points[i][1]), i});
        }
        for (auto e : ecd) {
            pq.push({e.first, e.second});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size() != 0) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
