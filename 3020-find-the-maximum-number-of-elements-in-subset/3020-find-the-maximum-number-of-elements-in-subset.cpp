class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        // Special handling for 1
        if (freq.count(1)) {
            ans = max(ans, (freq[1] % 2) ? freq[1] : freq[1] - 1);
        }

        const long long LIM = 31622; // floor(sqrt(1e9))

        for (auto &[start, c] : freq) {
            if (start == 1) continue;

            long long x = start;
            int cur = 0;

            while (true) {
                if (!freq.count(x)) {
                    cur--;          // previous level becomes the peak
                    break;
                }

                if (freq[x] == 1) {
                    cur++;          // use it as the peak
                    break;
                }

                // freq[x] >= 2
                if (x > LIM) {
                    // x*x cannot exist in nums, so x must be the peak
                    cur++;
                    break;
                }

                cur += 2;
                x = x * x;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};