class Solution {
    // int cnt=0;
    const int MOD=1e9+7; 
    int solve(int n,int k,int target,vector<vector<int>> &dp){
        if(dp[n][target]!=-1) return dp[n][target];
        if(n==0){
            if(target==0){
                return 1;
            }else{
                return 0;
            }
        }
        int ways=0;
        for(int face =1;face<=k;face++){
            if(face<=target){

              ways=(ways+solve(n-1,k,target-face,dp))%MOD;
            }
        }
        return dp[n][target]=ways;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        // return solve(n,k,target,dp);
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int ways=0;
                for(int face =1;face<=k;face++){
                    if(face<=j){
                      ways=(ways+dp[i-1][j-face])%MOD;
                    }
                }
                 dp[i][j]=ways;
            }
        }
        return dp[n][target];
    }
};