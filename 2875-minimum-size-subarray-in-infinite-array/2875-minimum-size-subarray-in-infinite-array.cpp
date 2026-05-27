class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
        }
        long long c = target / s;
        // n=((int)c+1)*n;
        target -= (c * s);
        if (target == 0) {
            return c * n;
        }
        for (int i = 0; i < 2 * n; i++) {
            nums.push_back(nums[i]);
        }
        int l = 0, r = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > target) {
                // cout<<sum<<" ";
                sum -= nums[l];
                l++;
            }
            if (sum == target) {
                ans = min(ans, r - l + 1);
            }
            // cout<<sum<<" ";
            r++;
        }
        return ans == INT_MAX ? -1 : ans + c * n;
    }
};