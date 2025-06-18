class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Min-heap priority queue: {difference, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        diff[0][0] = 0;

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [dif, pos] = pq.top(); pq.pop();
            int r = pos.first;
            int c = pos.second;

            if (r == n - 1 && c == m - 1) return dif;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int neweffort = max(abs(heights[r][c] - heights[nr][nc]), dif);
                    if (neweffort < diff[nr][nc]) {
                        diff[nr][nc] = neweffort;
                        pq.push({neweffort, {nr, nc}});
                    }
                }
            }
        }

        return 0; 
    }
};