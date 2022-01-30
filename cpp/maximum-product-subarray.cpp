/* Explanation
 * Easy to understand O(n) solution :
 * Its all about having odd or even numbers of negative integers. if the negative numbers are even, then the first pass will give the solution. If the negative numbers are odd, the second pass will give the solution.
 * 
 * class Solution {
 *     public int maxProduct(int[] nums) {
 *         int prod = 1;
 *         int result = Integer.MIN_VALUE;
 *         
 *         for (int i = 0; i < nums.length; i++) {
 *             prod = prod * nums[i];
 *             result = Math.max(prod, result);
 *             if(prod == 0) {
 *                 prod = 1;
 *             }
 *         }
 *         prod = 1;
 *         
 *         for (int i = nums.length - 1; i >= 0; i--) {
 *             prod = prod * nums[i];
 *             result = Math.max(prod, result);
 *             if(prod == 0) {
 *                 prod = 1;
 *             }      
 *         }
 *         return result;
 *     }
 * }
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lproduct = 1, rproduct = 1, max_product = INT_MIN;
        for (int i = 0; i <= nums.size() - 1; i++) {
            lproduct = (lproduct ? lproduct : 1) * nums[i];
            rproduct = (rproduct ? rproduct : 1) * nums[nums.size() - 1 - i];
            max_product = max(max_product, max(lproduct, rproduct));
        }
        return max_product;
    }
};
