class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // {maximum value, sum of original values, count}
        deque<array<long long, 3>> dq;

        long long cost = 0;
        long long ans = 0;

        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {

            long long x = nums[l];
            long long sum = x;
            long long cnt = 1;

            // Merge all groups whose maximum <= x
            while (!dq.empty() && dq.front()[0] <= x) {
                auto cur = dq.front();
                dq.pop_front();

                cost += (x - cur[0]) * cur[2];

                sum += cur[1];
                cnt += cur[2];
            }

            dq.push_front({x, sum, cnt});

            // Shrink window from the right
            while (cost > k) {
                auto &cur = dq.back();

                cost -= cur[0] - nums[r];
                cur[1] -= nums[r];
                cur[2]--;

                if (cur[2] == 0) {
                    dq.pop_back();
                }

                r--;
            }

            // All subarrays [l ... r] are valid
            ans += r - l + 1;
        }

        return ans;
    }
};
