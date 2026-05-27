class Solution {
    int solve(int index,vector<int>&nums,int lindex,int sign,vector<vector<vector<int>>> &dp){
        if(index==nums.size()) return 0;
        if(dp[index][lindex+1][sign+1]!=-1) return dp[index][lindex+1][sign+1];

        int notTake=solve(index+1,nums,lindex,sign,dp);

        int take=0;
        if(lindex==-1){
            take=1+solve(index+1,nums,index,0,dp);
        }else{
            int diff=nums[index]-nums[lindex];
            if(sign==0){
                if(diff>0){
                    take=1+solve(index+1,nums,index,-1,dp);
                }else if(diff<0) {
                    take=1+solve(index+1,nums,index,1,dp);
                }
            }
            else if(sign==1 && diff>0){
                take=1+solve(index+1,nums,index,-1,dp);
            }
            else if(sign==-1 && diff<0){
                take=1+solve(index+1,nums,index,1,dp);
            }
        }
        return dp[index][lindex+1][sign+1]= max(take,notTake);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size()+1,vector<int>(3,-1)));
        return solve(0,nums,-1,0,dp);
    }
};