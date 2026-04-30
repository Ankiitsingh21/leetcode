class Solution {
    int solve(int i,int j,vector<int>&arr,vector<vector<int>> &dp){
        if(j-i+1<3) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int index=i+1;index<j;index++){
            int cost=arr[i]*arr[index]*arr[j];
            cost+=solve(i,index,arr,dp)+solve(index,j,arr,dp);
            ans=min(ans,cost);
        }
        return dp[i][j]= ans;
    }
public:
    int minScoreTriangulation(vector<int>& arr) {
        // return solve(0,arr.size()-1,arr,dp);

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {

                // BASE CASE
                if(j - i + 1 < 3) {
                    dp[i][j] = 0;
                    continue;
                }

                int ans = INT_MAX;

                for(int k = i + 1; k < j; k++) {
                    int cost = arr[i] * arr[k] * arr[j]
                             + dp[i][k]
                             + dp[k][j];

                    ans = min(ans, cost);
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }
};