class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        for (auto &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            numCourses--;
            for (auto u : graph[cur]) {
                if (--indegree[u] == 0)
                    q.push(u);
            }
        }
        
        return numCourses == 0;
    }
};
