class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.length(), output = 0, end = s.length();
        while( s[end - 1] == ' ')
            end--;
        for (int i = end - 1; i >= 0; i--) {
            if (s[i] != ' ')
                output++;
            else 
                break;
        }
        return output;
    }
};
