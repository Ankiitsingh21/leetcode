class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr=0;
        int xo=0;
        for(int i=0;i<nums.size();i++){
            xorr^=i;
            xo^=nums[i];
        }
        xorr^=nums.size();
        return xorr^xo;
        int sum1=(nums.size()*(nums.size()+1))/2;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum1-sum;
    }
};