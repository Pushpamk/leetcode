class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[s.length()][s.length()];
        int n = s.length();
        
        int start = 0;
        int end = 0;
        for (int i = n - 1; i >= 0 ; i--) {
            for (int j = i; j < n ; j++) {
                dp[i][j] = (s[i] == s[j] && (j - i < 3 ||  dp[i + 1][j - 1] == 1));
                if(dp[i][j] && (j-i+1 > end)) {
                    start = i;
                    end = j-i+1;
                }
            }
        }
        
        return s.substr(start, end);
    }
};
