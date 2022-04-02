class Solution {
    public String removeDuplicates(String s) {
        Deque<Character> st = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (!st.isEmpty() && st.peek() == c)
                st.pop();
            else
                st.push(c);
        }
        String ans = "";
        for (char c : st)
            ans += c;
        String a = "";
        for (int i = ans.length() - 1; i >= 0 ; i--)
            a += ans.charAt(i);
        return a;
    }
}
