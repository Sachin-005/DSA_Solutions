class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<int>> dis(n,vector<int>(n, 1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        dis[0][0] = 1;
        q.push({1,{0,0}});
        int drow[8] = {-1,-1,-1,0,0,1,1,1};
        int dcol[8] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
         int d = q.top().first;
         int x = q.top().second.first;
         int y = q.top().second.second;
         q.pop();
         for(int i=0;i<8;i++){
            int nx = x+drow[i];
            int ny = y+dcol[i];
            if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                if(d+1 < dis[nx][ny]){
                    dis[nx][ny] = d+1;
                    q.push({dis[nx][ny],{nx,ny}});
                }
            }
         }
        }
        if(dis[n-1][n-1]!=1e9) return dis[n-1][n-1];
        return -1;

    }
};