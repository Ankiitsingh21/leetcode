class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        
        // dp[r] = number of subarrays ending at previous index
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            int val = num % k;

            // Start a new subarray containing only nums[i]
            ndp[val]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int newRemainder = (r * val) % k;
                ndp[newRemainder] += dp[r];
            }

            // Every subarray ending here contributes to the answer
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};