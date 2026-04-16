class Solution {
    int dfs(int index,int d,int maxi,vector<int> &arr,vector<vector<vector<int>>> &dp){
        if(index==arr.size()){
            return d!=0?INT_MAX/2:0;
        }
        if(d==0){
            return INT_MAX/2;
        }
        if(dp[index][d][maxi+1]!=-1) return dp[index][d][maxi+1];
        maxi=max(maxi,arr[index]);

        int ans=min(dfs(index+1,d,maxi,arr,dp),maxi+dfs(index+1,d-1,-1,arr,dp));


        return dp[index][d][maxi+1]=  ans;
    }
public:
    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        if(d>n) return -1;

       const int INF = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= d; k++) {

                int maxi = 0;

                for (int j = i; j >= 1; j--) {
                    maxi = max(maxi, arr[j - 1]);

                    if (dp[j - 1][k - 1] != INF) {
                        dp[i][k] = min(dp[i][k],
                                       dp[j - 1][k - 1] + maxi);
                    }
                }
            }
        }

        return dp[n][d];
    }
};