class Solution {
public:
    int count = 0;
    vector<int> id;
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i <= m - 1; i++) {
            for (int j = 0; j <= n - 1; j++) {
                if (grid[i][j] == '1')
                    count++;
            }
        }
        for (int i = 0; i <= m * n - 1; i++)
            id.push_back(i);
        for (int i = 0; i <= m - 1; i++) {
            for (int j = 0; j <= n - 1; j++) {
                if (grid[i][j] == '1') {
                    int p = i * n + j;
                    int q;
                    if (i > 0 && grid[i - 1][j] == '1') {
                        q = p - n;
                        unionf(p, q);
                    }
                    if (j > 0 && grid[i][j - 1] == '1') {
                        q = p - 1;
                        unionf(p, q);
                    }
                    if (i < grid.size() - 1 && grid[i + 1][j] == '1') {
                        q = p + n;
                        unionf(p, q);
                    }
                    if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') {
                        q = p + 1;
                        unionf(p, q);
                    }
                    
                }
            }
        }
        return count;
    }
    
    int find(int a) {
        while( a != id[a]) {
            a = id[a];
        }
        return a;
    }
    
    void unionf(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b)
            return;
        id[a] = b;
        count--;
    }
};
