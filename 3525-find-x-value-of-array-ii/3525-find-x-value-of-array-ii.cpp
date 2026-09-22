class Solution {
public:
    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, k;
    vector<Node> seg;

    Node merge(Node &a, Node &b) {
        Node res;

        // Product of the complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside a
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes that contain all of a
        // and some prefix of b
        for (int r = 0; r < k; r++) {
            int newRemainder = (a.prod * r) % k;
            res.cnt[newRemainder] += b.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int val = nums[l] % k;

            seg[node].prod = val;
            seg[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            int val = value % k;

            seg[node] = Node();
            seg[node].prod = val;
            seg[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        // Completely outside
        if (qr < l || r < ql) {
            // Empty segment
            Node empty;
            empty.prod = 1;
            return empty;
        }

        // Completely inside
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        // Handle empty sides
        bool leftEmpty = (r < ql || qr < l);
        bool rightEmpty = (mid + 1 > qr || ql > r);

        if (leftEmpty) return right;
        if (rightEmpty) return left;

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->n = nums.size();
        this->k = k;

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent point update
            update(1, 0, n - 1, index, value);

            // We need all prefixes of nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back((int)res.cnt[x]);
        }

        return ans;
    }
};