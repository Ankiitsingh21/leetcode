class Solution {
   int f(int i, int j, vector<int>& nums) {
    if (i == j) return nums[i];

    int takeLeft  = nums[i] - f(i + 1, j, nums);
    int takeRight = nums[j] - f(i, j - 1, nums);

    return max(takeLeft, takeRight);
}
public:
    bool predictTheWinner(vector<int>& nums) {
        return f(0, nums.size() - 1, nums) >= 0;
    }
};