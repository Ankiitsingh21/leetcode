class Solution {
    int count=0;
    bool isSafe(int row,int col,vector<vector<int>> &board){
        int x=row,y=col;

        //check upppp
        while(x>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
        }

        //check upper left diagonal
        x=row,y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }

        x=row,y=col;
        while(x>=0 && y<board.size()){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    void solve(vector<vector<int>> &board,int row){
        int n=board.size();
        if(row==n){
            count++;
            return ;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,board)){
                board[row][col]=1;
                solve(board,row+1);
                board[row][col]=0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(board,0);
        return count;
    }
};