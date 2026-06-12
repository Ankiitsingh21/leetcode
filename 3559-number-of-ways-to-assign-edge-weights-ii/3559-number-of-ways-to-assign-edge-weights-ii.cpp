class Solution {
    const int MOD = 1e9 + 7;
    int LOG = 17;
    vector<vector<int>> up;
    vector<int> depth;

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        up[node][0] = parent;

        for (int i = 1; i < LOG; i++) {
            up[node][i] = up[up[node][i-1]][i-1];
        }

        for (auto child : adj[node]) {
            if (child == parent) continue;

            depth[child] = depth[node] + 1;
            dfs(child, node, adj);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i)) {
                u = up[u][i];
            }
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        LOG = 18; // because n <= 1e5

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);

        dfs(1, 1, adj);

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int ancestor = lca(u, v);

            int edgesInPath = depth[u] + depth[v] - 2 * depth[ancestor];

            if (edgesInPath == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(power(2, edgesInPath - 1));
            }
        }

        return ans;
    }
};