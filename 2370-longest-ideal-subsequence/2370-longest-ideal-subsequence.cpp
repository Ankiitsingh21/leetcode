class Solution {
    int solve(int index, string& s, int k, int last, vector<vector<int>>& dp) {
        if (index == s.size())
            return 0;
        if (dp[index][last + 1] != -1)
            return dp[index][last + 1];
        // skipp
        int skip = solve(index + 1, s, k, last, dp);

        // fill
        int fill = 0;
        if (last == -1 || abs(s[index] - 'a' - last) <= k) {
            fill = 1 + solve(index + 1, s, k, s[index] - 'a', dp);
        }

        return dp[index][last + 1] = max(skip, fill);
    }

public:
    int longestIdealString(string s, int k) {
        // vector<vector<int>> dp(s.size()+1, vector<int>(27, 0));
        // return solve(0,s,k,-1,dp);
        vector<int> next(27,0),curr(27,0);
        for (int index = s.size() - 1; index >= 0; index--) {
            for (int last = -1; last <= 25; last++) {
                int skip = next[last+1];

                // fill
                int fill = 0;
                if (last == -1 || abs(s[index] - 'a' - last) <= k) {
                    fill = 1 + next[s[index] - 'a'+1];
                }

                curr[last + 1] = max(skip, fill);
            }
            next=curr;
        }
        return next[0];
    }
};