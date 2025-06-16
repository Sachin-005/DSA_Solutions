class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);       // Adjacency list
        vector<int> inDegree(numCourses, 0);       // In-degree of each course

        // Build the graph
        for (auto& x : prerequisites) {
            adj[x[1]].push_back(x[0]);             // x[1] → x[0]
            inDegree[x[0]]++;                      // Increase in-degree of course x[0]
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);                         // Start with courses that have no prerequisites
        }

        int completed = 0;                         // Count how many courses we can complete

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            completed++;                           // Mark course as completed

            for (int x : adj[t]) {
                inDegree[x]--;
                if (inDegree[x] == 0) {
                    q.push(x);                     // Ready to take this course
                }
            }
        }

        return completed == numCourses;            // If all courses completed, return true
    }
};
