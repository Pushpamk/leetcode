class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(ans, "", 0, 0, n);
        return ans;
    }
    
    void backtracking(vector<string>& ans, string tmp, int open, int close, int m) {
        if (tmp.size() == 2 * m) {
            ans.push_back(tmp);
            return;
        }
        if (open < m)
            backtracking(ans, tmp + '(', open + 1, close, m);
        if (close < open)
            backtracking(ans, tmp + ')', open, close + 1, m);
    }
};
