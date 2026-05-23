class Solution {
    int solve(vector<vector<int>> &arr,int index,int lindex ,vector<vector<int>> &dp){
        if(index==arr.size()) return 0;

        if(dp[index][lindex+1]!=-1) return dp[index][lindex+1];

        int take=0;
        if(lindex==-1 || arr[lindex][0]==arr[index][0]  || arr[lindex][1]<=arr[index][1]){
            take=arr[index][1]+solve(arr,index+1,index,dp);
        }

        int not_take=solve(arr,index+1,lindex,dp);

        return dp[index][lindex+1]= max(take,not_take);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<vector<int>> arr(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            arr[i][0]=ages[i];
            arr[i][1]=scores[i];
        }

        sort(arr.begin(),arr.end());

        // for(int i=0;i<n;i++){
        //     cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<endl;
        // }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        // return solve(arr,0,-1,dp);
        for(int index=n-1;index>=0;index--){
            for(int lindex=index-1;lindex>=-1;lindex--){
                int take=0;
                if(lindex==-1 || arr[lindex][0]==arr[index][0]  || arr[lindex][1]<=arr[index][1]){
                    take=arr[index][1]+dp[index+1][index+1];
                }

                int not_take=dp[index+1][lindex+1];

                 dp[index][lindex+1]= max(take,not_take);
            }
        }

        return dp[0][0];
    }
};