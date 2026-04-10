class Solution {
    void addSolution(vector<vector<string>> &ans, vector<vector<char>> &board, int n) {
    vector<string> temp;
    for (int i = 0; i < n; i++) {
        string row = "";
        for (int j = 0; j < n; j++) {
            row += board[i][j];
        }
        temp.push_back(row);
    }
    ans.push_back(temp);
}


    bool isSafe(int row,int col,vector<vector<char>> &board,int n){
        int x=row;
        int y=col;

        //checkleft
        while(y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }

        //check upper diagonal

        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }

        //check lower diagonal

        x=row;
        y=col;
        while(x<n && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>> &ans,vector<vector<char>> &board,int n){
        if(col==n){
            addSolution(ans,board,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        solve(0,ans,board,n);
        return ans;
    }
};