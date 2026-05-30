class SegmentTree {
public:
    int n;
    vector<int> st;

    SegmentTree(int n) : n(n) {
        st.assign(4 * n + 4, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            st[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node << 1, l, mid, idx, val);
        else
            update(node << 1 | 1, mid + 1, r, idx, val);

        st[node] = max(st[node << 1], st[node << 1 | 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return st[node];

        int mid = (l + r) >> 1;

        return max(
            query(node << 1, l, mid, ql, qr),
            query(node << 1 | 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int MAXX = 50000;

        set<int> pos;
        pos.insert(0);
        pos.insert(MAXX);

        for (auto &q : queries) {
            if (q[0] == 1)
                pos.insert(q[1]);
        }

        SegmentTree seg(MAXX);

        auto it = pos.begin();
        auto prevIt = it;
        ++it;

        for (; it != pos.end(); ++it) {
            seg.update(*it, *it - *prevIt);
            prevIt = it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {

            auto &q = queries[i];

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                int best = seg.query(0, x);

                auto it = pos.upper_bound(x);
                --it;

                best = max(best, x - *it);

                ans.push_back(best >= sz);
            }
            else {

                int x = q[1];

                auto cur = pos.find(x);
                auto prv = prev(cur);
                auto nxt = next(cur);

                seg.update(*nxt, *nxt - *prv);

                pos.erase(cur);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};