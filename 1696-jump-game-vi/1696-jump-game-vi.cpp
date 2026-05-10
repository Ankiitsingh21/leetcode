class Solution {
    int solve(int index,vector<int>&nums,int k,vector<int> &dp){
        if(index==nums.size()-1) return nums[index];
        if(dp[index]!=-1) return dp[index];
        int jumpIndex=index+k;
        if(jumpIndex>nums.size()-1){
            jumpIndex=nums.size()-1;
        }
        int filli=INT_MIN;
        for(int i=index+1;i<=jumpIndex;i++){
            filli=max(filli,nums[index]+solve(i,nums,k,dp));
        }

        // cout<<adj<<" "<<jump<<" "<<endl;
        return dp[index]= filli;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(),INT_MIN);
        deque<int> dq;
        int n=nums.size();
        dp[n-1]=nums[n-1];
        dq.push_back(n-1);
        for(int i=n-2;i>=0;i--){
            while(!dq.empty() && dq.front()>i+k){
                dq.pop_front();
            }
            dp[i]=nums[i]+dp[dq.front()];
            while(!dq.empty() && dp[dq.back()]<=dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[0];
    }
};