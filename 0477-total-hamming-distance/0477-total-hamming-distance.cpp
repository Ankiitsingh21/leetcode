class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < 32; i++) {
            int ones = 0;

            for(int num : nums) {
                ones += (num >> i) & 1;
            }

            sum += ones * (n - ones);
        }

        return sum;
    }
};