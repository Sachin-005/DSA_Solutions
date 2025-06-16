class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            for (auto& v : adj[i]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto& v : adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

       if (topo.size() == numCourses) {
            return topo;
        } else {
            return {}; // Ret

        }
        }
};