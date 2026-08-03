class Solution {
//     int solve(int i,int j,string s,string a,vector<vector<int>> &dp){
//     if(i==0){
//         return j;
//     }
//     if(j==0){
//         return i;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(s[i-1]==a[j-1]){
//         return dp[i][j]=0+solve(i-1,j-1,s,a,dp);
//     }
//     else{
//         int insert=1+solve(i,j-1,s,a,dp);
//         int replace=1+solve(i-1,j-1,s,a,dp);
//         int remove=1+solve(i-1,j,s,a,dp);
//         return dp[i][j]=min({insert,replace,remove});
//     }
// }
public:
    int minDistance(string s, string a) {
        int n=s.size(),m=a.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(s[i-1]==a[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        int insert=1+dp[i][j-1];
                        int replace=1+dp[i-1][j-1];
                        int remove=1+dp[i-1][j];
                         dp[i][j]=min({insert,replace,remove});
                    }
            }
        }
        return dp[n][m];
    }
};