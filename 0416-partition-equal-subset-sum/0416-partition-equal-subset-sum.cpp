class Solution {
    bool solve(vector<int>& nums,int target,int index,vector<vector<int>> &dp){
        if(target==0) return true;
        if(index==nums.size() || target<0) return false;

        if(dp[index][target]!=-1) return dp[index][target];

        bool take=solve(nums,target-nums[index],index+1,dp);

        bool notTake =solve(nums,target,index+1,dp);

        return dp[index][target] = take||notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;

        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum/2 +1,false));
        // return solve(nums,sum/2,0,dp);
        int t=sum/2;

        for(int i = 0; i < nums.size(); i++){
            dp[i][0] = true;
        }
        

        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=t;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][t];
    }
};