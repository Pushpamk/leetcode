class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> toposort;
        vector<int> indegree(numCourses, 0);

        if (numCourses == 1) {
            toposort.push_back(0);
            return toposort;
        }
        
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
            toposort.push_back(cur);
            for (auto u : graph[cur]) {
                if (!--indegree[u]) {
                    q.push(u);
                }
            }
        }
        if (numCourses != 0) {
            toposort.clear();
            return toposort;
        }
        return toposort;
    }
};
