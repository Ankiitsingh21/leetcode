class Solution {
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];


        int ans=INT_MAX;
        for(int index=i;index<=j;index++){
            int cost=cuts[j+1]-cuts[i-1];
            cost+=solve(i,index-1,cuts,dp)+solve(index+1,j,cuts,dp);
            ans=min(ans,cost);
        }
        return dp[i][j]= ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int N=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(N+2,vector<int>(N+2,0));
        // return solve(1,N,cuts,dp);
        for(int i=N;i>=1;i--){
            for(int j=i;j<=N;j++){
                 int ans=INT_MAX;
        for(int index=i;index<=j;index++){
            int cost=cuts[j+1]-cuts[i-1];
            cost+=dp[i][index-1]+dp[index+1][j];
            ans=min(ans,cost);
        }
         dp[i][j]= ans;
            }
        }



        return dp[1][N];
    }
};