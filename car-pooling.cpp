class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001, 0);
        for (auto t : trips) {
            stops[t[1]] += t[0];
            stops[t[2]] -= t[0];
        }
        for (int i = 0; i < 1001; i++) {
            capacity -= stops[i];
            if (capacity < 0)
                return false;
        }
        return true;
    }
};
