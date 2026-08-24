class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // prefix[i] = sum of stones[0 ... i-1]
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        // If Alice takes all stones initially.
        int ans = prefix[n];

        // Try every possible first merge.
        for (int i = n - 1; i >= 2; i--) {
            ans = max(ans, prefix[i] - ans);
        }

        return ans;
    }
};