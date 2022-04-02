class Solution {
public:
    int numTilePossibilities(string tiles) {
        // vector<bool> chosen(tiles.size(), false);
        vector<int> alpha(26, 0);
        for (auto c : tiles)
            alpha[c - 'A']++;
        
        return dfs(alpha);
    }
    int dfs(vector<int>& alpha) {
        int count = 0;
        for (int k = 0; k <= 25; k++) {
            if (alpha[k] == 0)
                continue;
            count++;
            alpha[k]--;
            count += dfs(alpha);
            alpha[k]++;
        }
        return count;
    }
};
