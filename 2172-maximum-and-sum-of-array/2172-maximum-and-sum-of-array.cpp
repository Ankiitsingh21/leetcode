class Solution {
    int dp[19][1 << 18];

    int solve(int index, int mask, vector<int>& nums, int numSlots) {
        if (index == nums.size()) return 0;
        if (dp[index][mask] != -1) return dp[index][mask];

        int filli = 0;
        for (int i = 0; i < numSlots; i++) {
            int cnt = (mask >> (2 * i)) & 3; // how many nums in slot i
            if (cnt < 2) {
                int newmask = mask + (1 << (2 * i)); // increment slot i count
                int contribution = nums[index] & (i + 1);
                filli = max(filli, contribution + solve(index + 1, newmask, nums, numSlots));
            }
        }

        return dp[index][mask] = filli;
    }

public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums, numSlots);
    }
};