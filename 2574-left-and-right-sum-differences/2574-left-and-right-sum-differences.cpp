class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int>suffix(nums.size(),0);
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        vector<int> ans(nums.size(),0);
        for(int i=0;i<ans.size();i++){
            ans[i]=abs(prefix[i]-suffix[i]);
        }
        return ans;
    }
};