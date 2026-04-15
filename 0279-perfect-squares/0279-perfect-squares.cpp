class Solution {
    bool isPerfect(int n){
        if (n < 0) return false;

    int x = sqrt(n);
    return x * x == n;
    }

    int solve(int index,vector<int> &arr,int target ,vector<vector<int>> &dp){
        if(index==0){
            if(target%arr[0]==0){
                return target/arr[0];
            }
            return 1e9;
        }
        if(dp[index][target] !=-1) return dp[index][target];

        int nottake=solve(index-1,arr,target,dp);
        int take=1e9;
        if(arr[index]<=target){
        // cout<<arr[index]<<" "<<target<<" "<<target-arr[index]<<endl;;
            take=1+solve(index,arr,target-arr[index],dp);
        }

        return dp[index][target] = min(nottake,take);
    }
public:
    int numSquares(int n) {
        if(n<=1) return n;
        vector<int> arr;
        for(int i=1;i<=n;i++){
            // cout<<"hi";
            if(isPerfect(i)){
                arr.push_back(i);
            }
        }

        vector<vector<int>> dp(arr.size(),vector<int>(n+1,-1));
        // return solve(arr.size()-1,arr,n,dp);
        for(int j=0;j<=n;j++){
            if(j%arr[0]==0){
                dp[0][j]=j/arr[0];
            }else{
                dp[0][j]=1e9;
            }
        }

        for(int index=1;index<arr.size();index++){
            for(int target=0;target<=n;target++){
                     int nottake=dp[index-1][target];
                     int take=1e9;
                     if(arr[index]<=target){
                     // cout<<arr[index]<<" "<<target<<" "<<target-arr[index]<<endl;;
                         take=1+dp[index][target-arr[index]];
                     }

                         dp[index][target] = min(nottake,take);
            }
        }

        return dp[arr.size()-1][n];
    }
};