class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> val(n), pos(n);
        for (int i = 0; i < n; i++) {
            val[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        // Component id in sorted order
        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (val[i] - val[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        // Furthest reachable in one edge
        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && val[r + 1] - val[i] <= maxDiff)
                r++;
            nxt[i] = r;
            if (r < i + 1)
                r = i + 1;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u > v)
                swap(u, v);

            int cur = u;
            int dist = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    dist += (1 << k);
                }
            }

            ans.push_back(dist + 1);
        }

        return ans;
    }
};