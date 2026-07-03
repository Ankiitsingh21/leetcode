class Solution {
public:
    bool check(long long limit,
               vector<vector<pair<int,int>>>& adj,
               vector<int> indegree,
               vector<bool>& online,
               long long k) {

        int n = online.size();

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] != LLONG_MAX) {
                for (auto &[v, w] : adj[u]) {

                    // Ignore edges whose cost is smaller than the threshold.
                    if (w < limit)
                        continue;

                    // Intermediate nodes must be online.
                    if (v != n - 1 && !online[v])
                        continue;

                    dist[v] = min(dist[v], dist[u] + 1LL * w);
                }
            }

            for (auto &[v, w] : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n);

        int mx = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            indegree[v]++;
            mx = max(mx, w);
        }

        int low = 0;
        int high = mx;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, adj, indegree, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};