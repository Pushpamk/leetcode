class Solution {
public:
    vector<int> id;
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        for (int i = 0; i <= n - 1; i++)
            id.push_back(i);
        
        vector<bool> ans;
        
        for (auto &r : requests) {
            int a = find(r[0]);
            int b = find(r[1]);
            bool isMatched = true;
            if (a != b) {
                for (auto &rs : restrictions) {
                    int x = find(rs[0]), y = find(rs[1]);
                    if ((a == x && b == y) || (a == y && b == x)) {
                        isMatched = false;
                        break;
                    }
                }
            }
            ans.push_back(isMatched);
            if (isMatched)
                union_friends(a, b);
        }
        return ans;
        
    }
    int find(int a) {
        if (a == id[a])
            return a;
        while (a != id[a])
            a = id[a];
        return a;
    }
    
    void union_friends(int a, int b) {
        id[find(a)] = find(b);
    }
};
