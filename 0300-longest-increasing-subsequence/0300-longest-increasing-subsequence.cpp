class Solution {
    int solve(int index, vector<int>& nums, int lindex,vector<vector<int>> &dp) {
        if (index == nums.size())
            return 0;

        if(dp[index][lindex+1]!=-1 )  return dp[index][lindex+1]; 
        int nottake = solve(index + 1, nums,lindex,dp);
        int take = 0;
        if (lindex == -1 || nums[index] > nums[lindex]) {
            take = 1 + solve(index + 1, nums, index,dp);
        }
        return dp[index][lindex+1]= max(take, nottake);
    }

public:
    int lengthOfLIS(vector<int>& nums) { 
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(0, nums, -1,dp); 
    }
};