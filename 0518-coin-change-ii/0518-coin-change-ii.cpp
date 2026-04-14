class Solution {
    int solve(int index,int amount,vector<int>&coins,vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(index==0){
            if(amount%coins[0]==0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[index][amount]!=-1) return dp[index][amount];

        int nottake=0+solve(index-1,amount,coins,dp);

        int take=0;
        if(coins[index]<=amount){
            take+=solve(index,amount-coins[index],coins,dp);
        }

        return dp[index][amount] =nottake+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp);
    }
};