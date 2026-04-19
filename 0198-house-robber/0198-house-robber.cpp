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
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n,-1);
        // return helper(n,nums,dp);

        dp[0]=nums[0];

        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
              pick+=dp[i-2];
            }
             int np=0+dp[i-1];
              dp[i] =max(pick,np);
        }
         return dp[n-1];
    }
};