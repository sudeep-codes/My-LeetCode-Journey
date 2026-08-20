class Solution {
public:

    int rows;
    int cols;
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index){
        if (index==word.length()){
            return true;
        }
        if(r<0||r>=rows||c<0||c>=cols||board[r][c]!=word[index]){
            return false;
        }
        char temp=board[r][c];
        board[r][c]='#';
        bool found=dfs(board, word, r+1, c, index+1)||dfs(board, word, r-1, c, index+1)||dfs(board, word, r, c+1, index+1)||dfs(board, word, r, c-1, index+1);
        board[r][c]=temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        for(int r=0; r<rows; ++r){
            for(int c=0; c<cols; ++c){
                if(dfs(board,word,r,c,0)){
                    return true;
                }
            }
        }
        return false;
    }
};