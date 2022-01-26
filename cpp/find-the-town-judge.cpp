class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> hash(n + 1, 0);
        for (auto &i : trust) {
            hash[i[0]] = -1;
            if (hash[i[1]] != -1)
                hash[i[1]]++;
        }
        for (int i = 1; i <= n; i++)
            if (hash[i] == n - 1 && hash[i] != -1)
                return i;
        return -1;
    }
};
