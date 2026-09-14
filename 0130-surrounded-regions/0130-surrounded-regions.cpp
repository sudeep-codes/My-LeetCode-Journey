class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& board, int rows, int cols){
        if(r<0||c<0||r>=rows||c>=cols||board[r][c]!='O') return;
        board[r][c]='E';
        dfs(r+1,c,board,rows,cols);
        dfs(r-1,c,board,rows,cols);
        dfs(r,c+1,board,rows,cols);
        dfs(r,c-1,board,rows,cols);
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()|board[0].empty()) return;
        int rows=board.size();
        int cols=board[0].size();
        for(int r=0; r<rows; ++r){
            for(int c=0; c<cols;++c){
                bool isBorder=(r==0||r==rows-1||c==0||c==cols-1);
                if(isBorder && board[r][c]=='O') dfs(r,c,board,rows,cols);
            }
        }
        for(int r=0; r<rows; ++r){
            for(int c=0; c<cols;++c){
                if(board[r][c]=='O') board[r][c]='X';
                else if(board[r][c]=='E') board[r][c]='O';
            }
        }
    }
};