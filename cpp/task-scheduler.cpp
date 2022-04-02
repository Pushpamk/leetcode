class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();
        
        priority_queue<pair<int, char>> pq;
        map<char, int> mp;
        for (char c : tasks)
            mp[c]++;
        for (auto m : mp)
            pq.push({m.second, m.first});
        int maxLen = (pq.top().first - 1) * (n + 1);
        int tmp = pq.top().first;
        pq.pop();
        int count = 0;
        while (!pq.empty()) {
            if (pq.top().first == tmp)
                count++;
            pq.pop();
        }
        cout<<count<<endl;
        int len = tasks.size();
        return max(maxLen + count + 1, len);
    }
};
