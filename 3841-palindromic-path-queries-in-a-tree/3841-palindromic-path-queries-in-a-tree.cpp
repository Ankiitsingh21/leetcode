class Solution {
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, initialMask;
    int timer, LOG;

    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void add(int idx, int val) {
            for (; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        }

        void rangeUpdate(int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        }

        int query(int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        }
    };

    void dfs(int root) {
        // Iterative DFS avoids recursion stack overflow.
        vector<array<int, 3>> st;
        st.push_back({root, -1, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = ++timer;

                if (p != -1) {
                    up[0][u] = p;
                    depth[u] = depth[p] + 1;
                    initialMask[u] =
                        initialMask[p] ^ (1 << (0)); // overwritten below
                }

                st.push_back({u, p, 1});

                for (int v : adj[u]) {
                    if (v == p) continue;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer;
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[j][u];
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        initialMask.assign(n, 0);
        timer = 0;

        // Iterative DFS with correct root-to-node masks.
        vector<array<int, 3>> st;
        st.push_back({0, -1, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = ++timer;
                up[0][u] = (p == -1 ? u : p);

                if (p != -1) {
                    depth[u] = depth[p] + 1;
                    initialMask[u] =
                        initialMask[p] ^ (1 << (s[u] - 'a'));
                } else {
                    initialMask[u] = 1 << (s[u] - 'a');
                }

                st.push_back({u, p, 1});

                for (int v : adj[u]) {
                    if (v != p)
                        st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }

        Fenwick bit(n);
        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta =
                    (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                if (delta != 0) {
                    bit.rangeUpdate(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int maskU = initialMask[u] ^ bit.query(tin[u]);
                int maskV = initialMask[v] ^ bit.query(tin[v]);

                int pathMask = maskU ^ maskV ^ (1 << (s[w] - 'a'));

                // At most one character may have odd frequency.
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};