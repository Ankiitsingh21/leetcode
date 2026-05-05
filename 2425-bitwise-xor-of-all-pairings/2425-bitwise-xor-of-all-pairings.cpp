class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorr = 0;
        if(nums2.size() % 2 != 0)
            for(int x : nums1) xorr ^= x;

        if(nums1.size() % 2 != 0)
            for(int x : nums2) xorr ^= x;

        return xorr;
    }
};