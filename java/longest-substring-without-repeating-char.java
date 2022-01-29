class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1)
            return s.length();
        int i = 0, j = 0, ans = Integer.MIN_VALUE;
        HashMap<Character, Integer> mp = new HashMap<Character, Integer>();
        while (j < s.length()) {
            mp.merge(s.charAt(j), 1, Integer::sum);
            if (mp.size() == j - i + 1) {
                ans = Math.max(ans, j - i + 1);
            }
            else {
                while (mp.size() < j - i + 1) {
                    mp.merge(s.charAt(i), -1, Integer::sum);
                    int v = mp.get(s.charAt(i));
                    if (v == 0)
                        mp.remove(s.charAt(i));
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
}
