class Solution {
    int solve(int index,vector<int> &arr,int cooldown,int buy ,vector<vector<vector<int>>> &dp){
        if(index==arr.size()) return 0;
        if(dp[index][buy][cooldown] !=-1) return dp[index][buy][cooldown] ;

        if(cooldown) return solve(index+1,arr,!cooldown,buy,dp);
        int profit=0;
        if(buy){
            profit=max((-arr[index]+solve(index+1,arr,cooldown,!buy,dp)),solve(index+1,arr,cooldown,buy,dp));
        }else{
            profit=max(((arr[index]+solve(index+1,arr,!cooldown,!buy,dp))),solve(index+1,arr,cooldown,buy,dp));
        }
        return dp[index][buy][cooldown] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,prices,0,1,dp);
    }
};