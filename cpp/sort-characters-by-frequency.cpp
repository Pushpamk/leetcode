class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        string ans = "";
        priority_queue<pair<int, char>> pq;
        for (auto m : mp) {
            pq.push({m.second, m.first});
        }
        while(pq.size() != 0) {
            ans += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
