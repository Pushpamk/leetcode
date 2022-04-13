class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < firstList.size() && j < secondList.size()) {
            int a_start = firstList[i][0], a_end = firstList[i][1];
            int b_start = secondList[j][0], b_end = secondList[j][1];
            if ( a_start <= b_end && a_end >= b_start) {
                ans.push_back({max(a_start, b_start), min(a_end, b_end)});
            }
            if (a_end <= b_end)
                i++;
            else
                j++;
        }
        return ans;
    }
};
