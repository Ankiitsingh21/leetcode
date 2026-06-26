class Solution {
public:
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int size) {
            n = size;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        long long query(int idx) {
            long long sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int offset = n + 2;
        Fenwick ft(2 * n + 5);

        long long ans = 0;
        int prefix = 0;

        // Empty prefix sum
        ft.update(prefix + offset, 1);

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            // Count previous prefix sums strictly smaller
            ans += ft.query(prefix + offset - 1);

            ft.update(prefix + offset, 1);
        }

        return ans;
    }
};