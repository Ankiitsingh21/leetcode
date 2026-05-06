class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr=0,xorrr=0;
        for(int i=0;i<nums.size();i++){
            xorr^=i;
            xorrr^=nums[i];
        }
        xorr=xorr^nums.size();
        return xorr^xorrr;
    }
};