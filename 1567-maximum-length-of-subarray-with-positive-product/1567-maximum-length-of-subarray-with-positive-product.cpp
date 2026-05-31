class Solution {
    int solve(int l, int r, int cnt, int first, int last) {
        if (l > r) return 0;

        // Even negatives -> whole segment
        if (cnt % 2 == 0)
            return r - l + 1;

        // Odd negatives
        int removeLeft = r - first;   // remove upto first negative
        int removeRight = last - l;   // remove from last negative onwards

        return max(removeLeft, removeRight);
    }

public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int l = 0;

        while (l < n) {

            // Skip zeros
            while (l < n && nums[l] == 0)
                l++;

            if (l >= n)
                break;

            int r = l;
            int cnt = 0;
            int first = -1;
            int last = -1;

            // Process one non-zero segment
            while (r < n && nums[r] != 0) {
                if (nums[r] < 0) {
                    cnt++;

                    if (first == -1)
                        first = r;

                    last = r;
                }
                r++;
            }

            ans = max(ans, solve(l, r - 1, cnt, first, last));

            l = r + 1;
        }

        return ans;
    }
};