class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (auto word : words) 
            mp[word]++;
        priority_queue<pair<int, string>> pq;
        
        for (auto e : mp) {
            pq.push({-1 * e.second, e.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        while(pq.size() != 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;    
    }
};
