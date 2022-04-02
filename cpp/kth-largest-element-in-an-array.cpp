class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int e : nums) {
            e *= -1;
            pq.push(e);
            if (pq.size() > k)
                pq.pop();
            
        }
        return pq.top() * -1;
    }
};
