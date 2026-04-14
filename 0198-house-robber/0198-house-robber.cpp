class Solution {
    int helper(int n,vector<int> &nums,vector<int> &dp){
        if(n==0){
            return nums[n];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+helper(n-2,nums,dp);
        int np=0+helper(n-1,nums,dp);
         dp[n] =max(pick,np);
         return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int> dp(n+1,-1);
        return helper(n,nums,dp);
    }
};