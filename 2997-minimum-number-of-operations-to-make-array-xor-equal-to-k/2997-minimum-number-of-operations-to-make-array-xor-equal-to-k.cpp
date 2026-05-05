class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr=0;
        for(int &num:nums) xorr^=num;
        return __builtin_popcount(xorr ^ k);
    }
};