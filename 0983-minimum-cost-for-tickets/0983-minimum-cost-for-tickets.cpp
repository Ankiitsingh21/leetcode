class Solution {
    int solve(int index,vector<int> &arr,vector<int> &costs,vector<int> &dp){
        if(index>=arr.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        int option1=solve(index+1,arr,costs,dp)+costs[0];

        int i;
        for(i=0;i<arr.size() && arr[i]<arr[index]+7;i++);
        int option2= solve(i,arr,costs,dp)+costs[1];


        for(i=0;i<arr.size() && arr[i]<arr[index]+30;i++);

        int option3=solve(i,arr,costs,dp)+costs[2];


        return dp[index]=min(option1,min(option2,option3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return solve(0,days,costs,dp);
    }
};