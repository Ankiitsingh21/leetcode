class Solution {
    vector<int> solve(string &s){
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                dp[i + 1] = min(dp[i] + 2, i + 1);
            } else {
                dp[i + 1] = dp[i];
            }
        }

        return dp;
    }

public:
    int minimumTime(string s) {
        int n = s.size();

        vector<int> prefix = solve(s);

        reverse(s.begin(), s.end());

        vector<int> rev = solve(s);

        vector<int> suffix(n + 1);

        for(int i = 0; i <= n; i++){
            suffix[i] = rev[n - i];
        }

        int ans = INT_MAX;

        for(int i = 0; i <= n; i++){
            ans = min(ans, prefix[i] + suffix[i]);
        }

        return ans;
    }
};