class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);

        // 1. Remove both from front
        int front = r + 1;

        // 2. Remove both from back
        int back = n - l;

        // 3. Remove one from front and one from back
        int both = (l + 1) + (n - r);

        return min({front, back, both});
    }
};