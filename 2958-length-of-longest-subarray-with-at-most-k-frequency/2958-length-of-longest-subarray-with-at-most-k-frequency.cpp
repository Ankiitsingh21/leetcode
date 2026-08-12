class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0;
        map<int,int> mpp;
        int ans=INT_MIN;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp[nums[r]]>k){
                mpp[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};