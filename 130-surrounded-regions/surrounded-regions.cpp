class Solution {
    void make_all(int i,int j,int n,int m,vector<vector<char>>&board,vector<vector<int>>&v){
        if(i>=n||i<0||j>=m||j<0||board[i][j]=='X')return;
        if(v[i][j]!=0)return;
        v[i][j]=1;
        board[i][j]='P';
        make_all(i+1,j,n,m,board,v);
        make_all(i-1,j,n,m,board,v);
        make_all(i,j+1,n,m,board,v);
        make_all(i,j-1,n,m,board,v);

    }
    void solve(int i,int j,int n,int m,vector<vector<char>>& board, vector<vector<int>>&visited)
    {
        if(i>=n||i<0||j>=m||j<0)return;
        if(visited[i][j]!=0)return;
        if(board[i][j]=='O')board[i][j]='X';
        visited[i][j]=1;
        solve(i+1,j,n,m,board,visited);
        solve(i-1,j,n,m,board,visited);
        solve(i,j+1,n,m,board,visited);
        solve(i,j-1,n,m,board,visited);

    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||i==n-1||j==0||j==m-1){
                    if(board[i][j]=='O'){
                        vector<vector<int>>v(n,vector<int>(m,0));
                        make_all(i,j,n,m,board,v);
                    }
                }
            }
        }
        vector<vector<int>>visited(n,vector<int>(m,0));
        solve(0,0,n,m,board,visited);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(board[i][j]=='P'){
                        board[i][j]='O';
                    }
            }
        }
        
            }
};