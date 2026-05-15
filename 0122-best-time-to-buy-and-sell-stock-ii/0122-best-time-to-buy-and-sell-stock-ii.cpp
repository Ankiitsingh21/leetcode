class Solution {
    int ans(vector<int> &arr,int n,int index,int buy,vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy){
            profit = max((ans(arr,n,index+1,!buy,dp)-arr[index]), (ans(arr,n,index+1,buy,dp)));
        }else{
            profit = max((arr[index]+ans(arr,n,index+1,!buy,dp)),(ans(arr,n,index+1,buy,dp)));
        }
        return dp[index][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return ans(prices,prices.size(),0,1,dp);
    }
};