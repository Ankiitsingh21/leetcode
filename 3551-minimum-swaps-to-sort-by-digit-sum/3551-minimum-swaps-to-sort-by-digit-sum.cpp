class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Create target sorted array
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int sa = digitSum(a);
            int sb = digitSum(b);

            if (sa != sb)
                return sa < sb;

            return a < b;
        });

        // Map value -> its target index
        unordered_map<int, int> targetIndex;

        for (int i = 0; i < n; i++) {
            targetIndex[sorted[i]] = i;
        }

        // Find cycles
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || targetIndex[nums[i]] == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = targetIndex[nums[j]];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};