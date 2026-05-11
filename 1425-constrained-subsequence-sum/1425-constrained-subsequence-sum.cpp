class Solution {
    // int solve(int index,vector<int>&nums,int k,vector<int> &dp){
    //     // cout<<index<<" ";
    //     if(index==nums.size()) return 0;
    //     if(dp[index]!=-1) return dp[index];

    //     //skip
    //     // int skip=solve(index+1,nums,k,dp);

    //     //int fill;
    //     int filli=nums[index];
    //     for(int i=1;i<=k;i++){
    //         if(index+i<nums.size()){

    //            filli=max(filli,nums[index]+solve(index+i,nums,k,dp));
    //         //    cout<<nums[index]<<" "<<index+i<<" "<<index<<" "<<endl;
    //         }
    //     }
    //     return dp[index]= filli;
    // }
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        dq.push_back(0);
        int ans=dp[0];
        for(int i=1;i<nums.size();i++){
            while(!dq.empty() && dq.front()<i-k){
                dq.pop_front();
            }
            dp[i] = nums[i] + max(0, dp[dq.front()]);

            ans = max(ans, dp[i]);
            while(!dq.empty() && dp[dq.back()]<=dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans;
    }
};