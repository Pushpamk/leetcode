class Solution {
public:
    vector<int> id;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        id.push_back(0);
        for (int i = 1; i <= n; i++)
            id.push_back(i);
        vector<int> ans;
        for (auto &e : edges) {
            int a = e[0];
            int b = e[1];
            if (find(a) == find(b)) {
                ans.push_back(a);
                ans.push_back(b);
                break;
            } else {
                unite(find(a), find(b));
            }
        }
        return ans;
    }
    
    int find(int a) {
        return a == id[a] ? a : find(id[a]);
    }
    
    void unite(int a, int b) {
        id[find(a)] = find(b);
    }
    
};
