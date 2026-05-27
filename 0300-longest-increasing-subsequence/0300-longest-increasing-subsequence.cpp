class Solution {
    int solve(int index, int lindex, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (index == nums.size())
            return 0;

        if (dp[index][lindex + 1] != -1)
            return dp[index][lindex + 1];
        int take = 0;
        if (lindex == -1 || nums[index] > nums[lindex]) {
            take = solve(index + 1, index, nums, dp) + 1;
        }
        int nottake = solve(index + 1, lindex, nums, dp);

        return dp[index][lindex + 1] = max(nottake, take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, -1));
        return solve(0, -1, nums, dp);

        for (int index = nums.size() - 1; index >= 0; index--) {
            for (int lindex = -1; lindex < index; lindex++) {
                int take = 0;
                if (lindex == -1 || nums[index] > nums[lindex]) {
                    take = dp[index + 1][index + 1] + 1;
                }
                int nottake = dp[index + 1][lindex + 1];

                dp[index][lindex + 1] = max(nottake, take);
            }
        }
        return dp[0][0];
    }
};