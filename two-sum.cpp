#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result(2);
        for (int i = 0; i < nums.size(); i++) {
            if (hash[abs(target - nums[i])]) {
                    result[0] = i;
                    result[1] = hash[abs(target - nums[i])];
                    break;
            }
            hash[abs(target - nums[i])] = i;
        }
        return result;
    }
};
