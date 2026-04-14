class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int mat[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){
                    mat[i][j]=0;
                }
                if(j==0){
                    mat[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    mat[i][j]=mat[i-1][j]+(mat[i][j-coins[i-1]]);
                }
                else{
                    mat[i][j]=mat[i-1][j];
                }
            }
        }
        return mat[n][amount];
    }
};