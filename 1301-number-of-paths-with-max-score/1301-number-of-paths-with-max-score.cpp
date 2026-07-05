class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<int, int> dfs(
        int i,
        int j,
        vector<string>& board,
        vector<vector<int>>& score,
        vector<vector<int>>& ways,
        vector<vector<int>>& vis
    ) {
        // Out of bounds or obstacle
        if (i < 0 || j < 0 || board[i][j] == 'X')
            return {-1, 0};

        // Reached E
        if (i == 0 && j == 0)
            return {0, 1};

        // Already computed
        if (vis[i][j])
            return {score[i][j], ways[i][j]};

        vis[i][j] = 1;

        int best = -1;
        long long cnt = 0;

        pair<int, int> up = dfs(i - 1, j, board, score, ways, vis);
        pair<int, int> left = dfs(i, j - 1, board, score, ways, vis);
        pair<int, int> diag = dfs(i - 1, j - 1, board, score, ways, vis);

        vector<pair<int, int>> prev;
        prev.push_back(up);
        prev.push_back(left);
        prev.push_back(diag);

        for (int k = 0; k < 3; k++) {

            int currScore = prev[k].first;
            int currWays = prev[k].second;

            if (currScore == -1)
                continue;

            if (currScore > best) {
                best = currScore;
                cnt = currWays;
            }
            else if (currScore == best) {
                cnt = (cnt + currWays) % MOD;
            }
        }

        if (best == -1) {
            score[i][j] = -1;
            ways[i][j] = 0;
            return {-1, 0};
        }

        int val = 0;

        if (board[i][j] != 'S')
            val = board[i][j] - '0';

        score[i][j] = best + val;
        ways[i][j] = cnt % MOD;

        return {score[i][j], ways[i][j]};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pair<int, int> ans = dfs(n - 1, n - 1, board, score, ways, vis);

        if (ans.first == -1)
            return {0, 0};

        return {ans.first, ans.second};
    }
};