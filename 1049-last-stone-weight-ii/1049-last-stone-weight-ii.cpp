class Solution {
    int solve(vector<int> &arr,int total,int index,int sum,int target,vector<vector<int>> &dp){
        if(total>=target || index==arr.size()){
            return abs(total-(sum-total));
        }
        if(dp[index][total]!=-1) return dp[index][total];


        return dp[index][total]= min(solve(arr,total,index+1,sum,target,dp),solve(arr,total+arr[index],index+1,sum,target,dp));
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
        }

        int target=ceil(sum/2);

        vector<vector<int>> dp(stones.size()+1,vector<int>(target+1,-1));
        return solve(stones,0,0,sum,target,dp);
    }
};