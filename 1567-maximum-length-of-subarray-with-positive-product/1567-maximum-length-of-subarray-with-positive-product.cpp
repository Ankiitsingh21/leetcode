class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int negCount = 0;
        for (int i = l; i <= r; i++)
            if (nums[i] < 0) negCount++;
        
        // whole segment is positive product
        if (negCount % 2 == 0) return r - l + 1;
        
        // remove first negative → take subarray after it
        int firstNeg = l;
        while (nums[firstNeg] > 0) firstNeg++;
        
        // remove last negative → take subarray before it
        int lastNeg = r;
        while (nums[lastNeg] > 0) lastNeg--;
        
        int removeFirst = r - firstNeg;      // subarray from firstNeg+1 to r
        int removeLast  = lastNeg - l;       // subarray from l to lastNeg-1
        
        return max(removeFirst, removeLast);
    }

    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int l = 0;

        for (int i = 0; i <= n; i++) {
            // hit a zero or end of array → process segment [l, i-1]
            if (i == n || nums[i] == 0) {
                if (i > l)  // non-empty segment
                    ans = max(ans, solve(nums, l, i - 1));
                l = i + 1;
            }
        }

        return ans;
    }
};