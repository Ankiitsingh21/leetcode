class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) cnt++;
        }
        return nums[n-1]>nums[0]?cnt+1<=1:cnt<=1;
    }
};