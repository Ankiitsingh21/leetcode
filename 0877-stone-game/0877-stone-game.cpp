class Solution {
    int solve(int i,int j,vector<int> &nums,vector<vector<int>>&dp,int turn){
        if(i>j) return 0;

        if(dp[i][j]!=INT_MIN) return dp[i][j];
        if(turn ==0) {
            int takeL=nums[i]+solve(i+1,j,nums,dp,!turn);
            int takeR=nums[j]+solve(i,j-1,nums,dp,!turn);
            return dp[i][j]=max(takeL,takeR);
        }else{
            int takeL=-nums[i]+solve(i+1,j,nums,dp,!turn);
            int takeR=-nums[j]+solve(i,j-1,nums,dp,!turn);
            return dp[i][j]=max(takeL,takeR);
        }
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> arr(n,vector<int>(n,INT_MIN));
        return solve(0,n-1,piles,arr,0)>0;
    }
};