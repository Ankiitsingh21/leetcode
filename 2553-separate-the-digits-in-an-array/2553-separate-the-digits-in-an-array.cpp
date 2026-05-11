class Solution {
    vector<int> solve(int n){
        vector<int> ans;
        while(n>0){
            int a=n%10;
            ans.push_back(a);
            n=n/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=10){
                vector<int> arr=solve(nums[i]);
                for(int j=0;j<arr.size();j++){
                    ans.push_back(arr[j]);
                }
            }else{
                
            ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};