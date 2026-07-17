class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = frequency of x
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cnt[g] = how many numbers are divisible by g
        vector<long long> cnt(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int multiple = g; multiple <= mx; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }

        // exact[g] = number of pairs having gcd exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            long long c = cnt[g];

            // all pairs divisible by g
            exact[g] = c * (c - 1) / 2;

            // subtract pairs having gcd = 2g,3g,...
            for (int multiple = 2 * g; multiple <= mx; multiple += g) {
                exact[g] -= exact[multiple];
            }
        }

        // prefix[i] = number of pairs whose gcd <= i
        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {

            // queries are 0-indexed
            int g = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }
};