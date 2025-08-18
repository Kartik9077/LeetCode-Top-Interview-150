int row[4]={1,-1,0,0};
int col[4]={0,0,-1,1};
int n,m;

class Solution {
    bool solve(vector<vector<char>>&board,string s,int start,int end,int n,int m,int mahakal){
        if(mahakal==s.length()){
            return 1;
        }
        if(start>=n || end>=m|| start<0||end<0||board[start][end]!=s[mahakal] )return 0;
        char temp=board[start][end];
board[start][end]='#';
        for(int k=0;k<4;k++){
           
                {
                    if(solve(board,s,start+row[k],end+col[k],n,m,mahakal+1))
                    return 1;
                }
        }
        board[start][end]=temp;
        return 0;

        
       
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
      int n=board.size();
      int m=board[0].size();
         queue<pair<int,int>>q;
         for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         if(board[i][j]==word[0]){
            q.push(make_pair(i,j));

         }
         while(!q.empty()){
            int first=q.front().first;
            int sec=q.front().second;
            q.pop();
            if(solve(board,word,first,sec,n,m,0))return 1;

         }
         return 0;


    }
};