class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxi=1;
        int start=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                maxi=max(maxi,i-start+1);
            }else{
                start=i;
            }
        }

        return maxi;
    }
};