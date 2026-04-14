class Solution {
    int solve(int n,vector<int> &arr ,vector<int> &dp){
        if(n==0){
            return arr[0];
        }
        if(n<0){
            return 0;
        }

        if(dp[n]!=-1) return dp[n];

        int pick=arr[n]+solve(n-2,arr,dp);
        int np=solve(n-1,arr,dp);

        return dp[n]= max(np,pick);
    }
public:
    int deleteAndEarn(vector<int>& nums) {

        // sort(nums.begin(),nums.end());
        

        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int n=maxi+1;
        vector<int> arr(n);

        for(int i=0;i<nums.size();i++){
            arr[nums[i]]+=nums[i];
        }

        vector<int> dp(n,-1);
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        return solve(n-1,arr,dp);

    }
};