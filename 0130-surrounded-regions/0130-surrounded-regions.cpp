class Solution {
public:
    vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O') dfs(board,0,i,n,m);
        }
        for(int i=1;i<n;i++)
        {
            if(board[i][0]=='O') dfs(board,i,0,n,m);
        }
        for(int i=1;i<m;i++)
        {
            if(board[n-1][i]=='O') dfs(board,n-1,i,n,m);
        }
        for(int i=1;i<n-1;i++)
        {
            if(board[i][m-1]=='O') dfs(board,i,m-1,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
    void dfs(vector<vector<char>>& board , int i , int j,int& n , int& m)
    {

        board[i][j] = '#';
        for(auto d: dir)
        {
            int nx = i + d.first;
            int ny = j + d.second;

            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O')
            {
                dfs(board,nx,ny,n,m);
            }
        }
    }
};