class Solution {
    long long solve(int index,vector<vector<int>>& questions,int lindex,vector<long long> &dp){
        if(index==questions.size()) return 0;

        if(lindex>0) return solve(index+1,questions,lindex-1,dp);

        if(dp[index]!=-1) return dp[index];
        //skip
        long long skippi= solve(index+1,questions,lindex,dp);

        //filli
        long long fill=questions[index][0]+solve(index+1,questions,questions[index][1],dp);

        return dp[index]= max(skippi,fill);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        // vector<vector<long long>> dp(n,vector<long long>(n,-1));
        vector<long long> dp(n,-1);
        return solve(0,questions,0,dp);
    }
};