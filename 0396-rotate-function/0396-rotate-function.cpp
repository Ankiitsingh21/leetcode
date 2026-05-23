class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int f = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i]);
            f+=(i*nums[i]);
        }

        int res = f;
        for (int i = 0; i < n ; i++) {
            int newF = f + sum - n * nums[n - 1 - i];
            res = max(res, newF);
            f = newF;
        }
        return res;
    }
};