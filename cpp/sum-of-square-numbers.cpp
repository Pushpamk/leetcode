class Solution {
    /**
    * Any positive number nn is expressible as a sum of two squares if and only if the prime factorization of nn, every prime     * of the form (4k+3)(4k+3) occurs an even number of times.
    */
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            if (c % i == 0) {
                while (c % i == 0) {
                    ++count;
                    c /= i;
                }
            }
            if (i % 4 == 3 && count % 2 == 1)
                return false;
        }
        return c % 4 != 3;
    }
};
