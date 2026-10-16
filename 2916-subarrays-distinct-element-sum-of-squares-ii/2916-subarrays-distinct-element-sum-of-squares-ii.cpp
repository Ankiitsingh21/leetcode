class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;   // sum of distinct counts
        long long sq = 0;    // sum of squares of distinct counts
        long long lazy = 0;  // pending addition
    };

    vector<Node> seg;

    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;

        // (d + x)^2 = d^2 + 2*x*d + x^2
        seg[node].sq =
            (seg[node].sq
            + 2LL * x % MOD * seg[node].sum
            + x * x % MOD * (len % MOD)) % MOD;

        seg[node].sum =
            (seg[node].sum + x * (len % MOD)) % MOD;

        seg[node].lazy = (seg[node].lazy + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, seg[node].lazy);
        apply(node * 2 + 1, mid + 1, r, seg[node].lazy);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

    long long querySquareSum() {
        return seg[1].sq;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        seg.resize(4 * n + 5);

        /*
            For every right endpoint i:

            position l represents the subarray nums[l...i].

            We maintain:
                value[l] = number of distinct elements in nums[l...i]

            When nums[i] is added:

            Let p = previous occurrence of nums[i].

            For every l in [p + 1, i],
            nums[i] was NOT already present in nums[l...i-1].

            Therefore distinct count increases by 1.

            So we perform:

                range add +1 on [p+1, i]

            The segment tree maintains:
                sum(value[l])
                sum(value[l]^2)

            The latter gives the sum of squared distinct counts
            for all subarrays ending at i.
        */

        vector<int> last(100001, -1);

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            int p = last[x];

            // Distinct count increases for left endpoints
            // from p+1 through i.
            update(1, 0, n - 1, p + 1, i, 1);

            last[x] = i;

            // Sum of squares of distinct counts
            // for all subarrays ending at i.
            answer += querySquareSum();
            answer %= MOD;
        }

        return answer;
    }
};