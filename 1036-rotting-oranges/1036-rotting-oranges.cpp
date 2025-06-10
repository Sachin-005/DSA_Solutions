class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int tot = 0, rotten = 0;

        // Initialize the queue with all initially rotten oranges
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++; // count all non-empty cells
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int minutes = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int size = q.size();
            rotten += size;  

            for(int i = 0; i < size; ++i) {
                auto [x, y] = q.front(); q.pop();
                for(int d = 0; d < 4; ++d) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            if(!q.empty()) minutes++;
        }

        return (tot == rotten) ? minutes : -1;
    }
};
