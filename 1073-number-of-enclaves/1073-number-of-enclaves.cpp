class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int delRow[],int delCol[], int x, int y){
        visited[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x+delRow[i];
            int ny = y+delCol[i];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && visited[nx][ny] == 0 && grid[nx][ny] == 1){
                dfs(grid,visited,delRow,delCol,nx,ny);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        int delRow[] ={-1,1,0,0};
        int delCol[] ={0,0,-1,1};

        for(int i=0;i<m;i++){
            if(grid[0][i] == 1 && visited[0][i]==0){
                dfs(grid,visited,delRow,delCol,0,i);
            }
            if(grid[n-1][i] == 1 && visited[n-1][i]==0){
                dfs(grid,visited,delRow,delCol,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1 && visited[i][0]==0){
                 dfs(grid,visited,delRow,delCol,i,0);
            }
            if(grid[i][m-1] == 1 && visited[i][m-1]==0){
                dfs(grid,visited,delRow,delCol,i,m-1);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1)
                cnt++;
            }
        }
        return cnt;
    }
};