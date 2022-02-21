class Solution {
public:
    int minOperations(int n) {
        int half = 0;
        half = n % 2 == 0 ? (n / 2) - 1 : n / 2;
        int ans = 0;
        for (int i = 0; i <= half; i++)
            ans += n - 1 - 2*i;
        return ans;
    }
};
