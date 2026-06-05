class Solution {
public:
    pair<long long, long long> dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    pair<long long, long long> solve(int idx, int prev2, int prev1, int tight,
                                     int started, string& s) {

        if (idx == s.size()) {
            return {1, 0};
        }

        if (vis[idx][prev2 + 1][prev1 + 1][tight][started])
            return dp[idx][prev2 + 1][prev1 + 1][tight][started];

        long long ways = 0;
        long long waves = 0;

        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            int ntight = tight && (d == limit);

            if (started == 0 && d == 0) {

                auto temp = solve(idx + 1, -1, -1, ntight, 0, s);

                ways += temp.first;
                waves += temp.second;

            } else {

                int add = 0;

                if (prev2 != -1) {

                    if (prev1 > prev2 && prev1 > d)
                        add = 1;

                    if (prev1 < prev2 && prev1 < d)
                        add = 1;
                }

                auto temp = solve(idx + 1, prev1, d, ntight, 1, s);

                ways += temp.first;

                waves += temp.second + add * temp.first;
            }
        }

        vis[idx][prev2 + 1][prev1 + 1][tight][started] = true;

        return dp[idx][prev2 + 1][prev1 + 1][tight][started] = {ways, waves};
    }

    long long count(long long n) {

        if (n <= 0)
            return 0;

        string s = to_string(n);

        memset(vis, false, sizeof(vis));

        return solve(0, -1, -1, 1, 0, s).second;
    }

    long long totalWaviness(long long num1, long long num2) {

        return count(num2) - count(num1 - 1);
    }
};