class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        bool hadNonZero = false;
        for (int& x : nums) {
            xorr ^= x;
            if (x != 0) {
                hadNonZero = true;
            }
        }
        if (xorr != 0)
            return n;
        if (hadNonZero)
            return n - 1;
        return 0;
    }
};