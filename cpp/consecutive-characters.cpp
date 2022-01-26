class Solution {
public:
    int maxPower(string s) {
        if (s.length() <= 1)
            return s.length();
        int ans = 1, i = 0, count = 1;
        for (int j = 1; j < s.length(); j++) {
            if (s[j] != s[i]) {
                i = j;
                count = max(count,ans);
                ans = 1;
            }
            else
                ans++;
        }
        return max(ans, count);
    }
};
