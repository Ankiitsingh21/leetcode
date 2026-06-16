class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++){
            // cout<<i<<" "<<nums[i]<<" "<<nums[i-1]<<endl;
            if(nums[i]<=nums[i-1]){
                int sum=nums[i-1]-nums[i]+1;
                nums[i]+=sum;
                ans+=sum;
            }
        }
        return ans;
    }
};