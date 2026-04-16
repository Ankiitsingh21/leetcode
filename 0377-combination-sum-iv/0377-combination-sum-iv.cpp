class Solution {
    int solve(vector<int> & nums,int target,vector<int> &dp){
       if(target==0) return 1;
       if(target<1) return 0;
       if(dp[target]!=-1) return dp[target];

       int ways=0;
       for(int num:nums){
        ways+=solve(nums,target-num,dp);
       }
       return dp[target]= ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);
        // return solve(nums,target,dp);
        if(target==0) return 1;
        

        dp[0]=1;
        for(int i=1;i<=target;i++){
            // int ways=0;
            
            for(int num:nums){
                if(i>=num){

                    dp[i]+=dp[i-num];
                }
            }
            //  dp[i]= ways;
        }
        return dp[target];
    }
};