class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0, count = 0;
        unordered_map<int, int> hash;
        // because the prefixsum initially was zero before start hence we have to keep that also in mind and update in map so whenever the sum becomes zero that means the subarray from 0 to that position has equal 1s and 0s
        hash[0] = -1;
        for (int i = 0; i <= nums.size() - 1; i++) {
            count += nums[i] == 1? 1 : -1;
            cout<<count<<endl;
            if (hash.count(count)) {
                maxLen = max(maxLen, i - hash[count]);
            }
            else {
                hash[count] = i;
            }
        }
        return maxLen;
    }
};
