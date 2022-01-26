class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int length = log2(n) + 1;
        int temp = pow(2, length) - 1; // can be written as (1 << length) - 1
        return n ^ temp;
    }
};
