class Solution {
public:
void dfs(vector<vector<char>>& board,vector<vector<int>>&visited,int row,int col,int n,int m)
{
    visited[row][col]=1;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int r=row+dr[i];
        int c=col+dc[i];
        if(r>=0&&r<n&&c>=0&&c<m&&visited[r][c]==0&&board[r][c]=='O')
        {
            dfs(board,visited,r,c,n,m);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O'&&visited[0][j]==0)
            {
                dfs(board,visited,0,j,n,m);
            }
            if(board[n-1][j]=='O'&&visited[n-1][j]==0)
            {
                dfs(board,visited,n-1,j,n,m);
            }
        }
        for(int j=0;j<n;j++)
        {
            if(board[j][0]=='O'&&visited[j][0]==0)
            {
                dfs(board,visited,j,0,n,m);
            }
            if(board[j][m-1]=='O'&&visited[j][m-1]==0)
            {
                dfs(board,visited,j,m-1,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0&&board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};