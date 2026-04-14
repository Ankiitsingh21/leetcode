class Solution {
    int solve(int i,int amount,vector<int> &arr,vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if (i < 0 || amount < 0) return INT_MAX - 1; 
        if(dp[i][amount]!=-1)return dp[i][amount];

        int nottake=solve(i-1,amount,arr,dp);
        int take=INT_MAX-1;
        if(arr[i]<=amount){
            take=1+solve(i,amount-arr[i],arr,dp);
        }
        dp[i][amount]=min(nottake,take);
        return min(nottake,take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int result = solve(n - 1, amount, coins,dp);

        // If result is impossible, return -1
        return result == INT_MAX - 1 ? -1 : result;
    }
};
