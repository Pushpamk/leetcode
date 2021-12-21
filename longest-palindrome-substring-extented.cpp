class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "")
            return "";
        
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = extentedAroundCenter(s, i, i); // for "racecar", for odd length
            int len2 = extentedAroundCenter(s, i, i + 1); // for "abba", even length
            int len = max(len1, len2);
            cout<<len;
            if ( len > end - start) {
                start = i - ((len - 1)/2);
                end = i + ((len)/2);
            }
        }
        return s.substr(start, end - start + 1);
    }
    
private:
    int extentedAroundCenter(string s, int left, int right) {
        if (s == "" && left > right)
            return 0;
        
        while( left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
