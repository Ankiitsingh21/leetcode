class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        int target=totalSum-x;
        int l=0,r=0,ans=INT_MIN,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(l <= r && sum>target){
                sum-=nums[l];
                l++;
            }
            if(sum==target){
             ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans==INT_MIN?-1:nums.size()-ans;
    }
};