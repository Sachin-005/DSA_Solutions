class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        pq.push({0, 0, 0});
        visited[0][0] = true;

        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            int row = cur[1];
            int cost = cur[0];
            int col = cur[2];
            if (row == m - 1 && col == n - 1) {
                return cost;
            }

            for (vector<int>& dr : dir) {
                int newR = row + dr[0];
                int newC = col + dr[1];

                if (newR >= 0 && newR < m && newC >= 0 && newC < n &&
                    !visited[newR][newC]) {
                    visited[newR][newC] = true;
                    if (grid[newR][newC] == 1) {
                        pq.push({cost + 1, newR, newC});
                    } else {
                        pq.push({cost, newR, newC});
                    }
                }
            }
        }
        return 0;
    }
};