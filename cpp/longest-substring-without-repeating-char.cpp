class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        int i = 0, j = 0, ans = INT_MIN;
        unordered_map<char, int> mp;
        while (j < s.size()) {
            mp[s[j]]++;
            
            if (mp.size() == j - i + 1) {
                ans = max(ans, j - i + 1);
                j++;
            }
            else {
                while (mp.size() < j - i + 1) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
