class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid[0].size();
        int n=obstacleGrid.size();
         vector<vector<int>> dp(n,vector<int>(m,0));
         if(obstacleGrid[0][0]==-1) return 0;
         dp[0][0]=1;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if (obstacleGrid[i][j] == 1) {
                      dp[i][j] = 0; // Skip obstacle cells
                      continue;
                  }
                  if (i > 0) dp[i][j] += dp[i - 1][j]; // Add paths from above
                  if (j > 0) dp[i][j] += dp[i][j - 1]; // Add paths from the left
             }
         }
         return dp[n-1][m-1];
    }
};