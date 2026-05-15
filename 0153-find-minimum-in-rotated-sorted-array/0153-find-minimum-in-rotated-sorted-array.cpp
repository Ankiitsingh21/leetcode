class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int mid=low+(high-low)/2;
        // int ans=INT_MAX;
        while(low<high){
        //    int  mid=low+(high-low)/2;
            if(nums[high]<nums[mid]){
                low=mid+1;
            }else{
                high=mid;
            }
            mid=low+(high-low)/2;
            // ans=min(ans,nums[mid]);
            // cout<<nums[mid]<<endl;
        }
        return nums[low];
    }
};