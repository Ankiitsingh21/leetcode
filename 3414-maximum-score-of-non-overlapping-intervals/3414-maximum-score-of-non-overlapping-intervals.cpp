class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices; // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original_index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by left endpoint
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0]) return x[0] < y[0];
            return x[1] < y[1];
        });

        // Find next non-overlapping interval for every interval.
        vector<int> next(n);

        vector<long long> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        for (int i = 0; i < n; i++) {
            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        // dp[i][k]:
        // best answer using intervals [i ... n-1]
        // with at most k intervals.
        vector<array<State, 5>> dp(n + 1);

        // dp[n][k] = empty answer with score 0
        for (int k = 0; k <= 4; k++) {
            dp[n][k].score = 0;
            dp[n][k].indices.clear();
        }

        for (int i = n - 1; i >= 0; i--) {
            // With 0 intervals allowed, answer is empty.
            dp[i][0] = dp[i + 1][0];

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip current interval
                State skip = dp[i + 1][k];

                // Option 2: take current interval
                State take = dp[next[i]][k - 1];
                take.score += a[i][2];

                // Insert original index so that indices remain sorted.
                int originalIndex = (int)a[i][3];

                auto pos = lower_bound(
                    take.indices.begin(),
                    take.indices.end(),
                    originalIndex
                );

                take.indices.insert(pos, originalIndex);

                // Choose maximum score.
                // If scores tie, lexicographically smallest indices.
                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].indices;
    }
};