class Solution {
    const int MOD=1e9+7;
    int solve(int n,vector<int> &dp){
        if(dp[n]!=-1) return dp[n];
        if(n==1 || n==2){
            return n;
        }
        if(n==3){
            return 5;
        }

        return dp[n]=((2*solve(n-1,dp))%MOD + (solve(n-3,dp))%MOD)%MOD;

    }
public:
    int numTilings(int n) {
        // if(n==1 || n==2){
        //     return n;
        // }
        // if(n==3){
        //     return 5;
        // }
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        if(n >= 2) dp[2] = 2;
        if(n >= 3) dp[3] = 5;
        for(int i=4;i<=n;i++){
            // if(i>3){
            dp[i]=((2*dp[i-1])%MOD + (dp[i-3])%MOD)%MOD;
            // }
        }
        return dp[n];
    }
};