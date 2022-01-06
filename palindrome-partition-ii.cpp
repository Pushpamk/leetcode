class Solution {
public:
    int minCut(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int ans = solve(s, 0, s.size() - 1, dp);
        return ans;
    }
    
private:
    
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j || isPalindrome(s, i, j))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            if (isPalindrome(s, i, k)) // because we want min cut, so if left is palindrome then we can check only right part
                ans = min(ans, 1 + solve(s, k + 1, j, dp));
        }
        
        return dp[i][j] = ans;
    }
    
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
