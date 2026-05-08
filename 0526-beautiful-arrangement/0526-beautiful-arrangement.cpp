class Solution {
    int cnt=0;
    void solve(int index,vector<int>&nums){
        if(index>=nums.size()){
            cnt++;
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            if(((index+1)%nums[index]==0)||(nums[index]%(index+1)==0)) solve(index+1,nums);

            swap(nums[index],nums[i]);
        }
        return;
    }
public:
    int countArrangement(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        solve(0,nums);
        return cnt;
    }
};