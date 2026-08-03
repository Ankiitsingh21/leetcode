class Solution {
    int solve(int index,int turn ,vector<int>&nums,vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index][turn] !=INT_MIN) return dp[index][turn];
        if(turn==0){
            int ans=INT_MIN;
            int sum=0;
            for(int i=index;i<nums.size() && i<index+3;i++){
                sum+=nums[i];
                ans=max(ans,sum+solve(i+1,!turn,nums,dp));
            }
            return dp[index][turn] = ans;
        }
        else{
            int ans=INT_MAX;
            for(int i=index;i<nums.size() && i<index+3;i++){
                ans=min(ans,solve(i+1,!turn,nums,dp));
            }
            return dp[index][turn] = ans; 
        }
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int sum=0;
        for(int num:stoneValue){
            sum+=num;
        }
        vector<vector<int>> dp(stoneValue.size(),vector<int>(2,INT_MIN));
        int alice=solve(0,0,stoneValue,dp);
        int bob=sum-alice;
        if(alice==bob) return "Tie";
        return alice>bob?"Alice":"Bob";
    }
};