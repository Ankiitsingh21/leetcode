
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            // Previous DP states before processing current element
            int prev = dp[x];
            int prevMinusOne = dp[x - 1];

            // Case 1: Keep x unchanged
            dp[x] = max(dp[x], prevMinusOne + 1);

            // Case 2: Increase x to x + 1
            dp[x + 1] = max(dp[x + 1], prev + 1);

            ans = max(ans, max(dp[x], dp[x + 1]));
        }

        return ans;
    }
};
