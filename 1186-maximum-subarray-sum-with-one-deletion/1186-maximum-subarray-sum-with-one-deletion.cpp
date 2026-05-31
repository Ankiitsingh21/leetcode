class Solution {
    int solve(int index, int sign, int started, vector<int>& arr,
              vector<vector<vector<int>>> &dp) {
        if (index == arr.size()) {
            return started ? 0 : -1e9;
        }
        if (dp[index][sign][started] != 1e9)
            return dp[index][sign][started] ;
        if (!started) {
            int skip = solve(index + 1, 0, 0, arr, dp);
            int start = arr[index] + solve(index + 1, 0, 1, arr, dp);
            return dp[index][sign][started] = max(skip, start);
        }
        // int nottake=solve(index+1,0,arr);
        // if(sign==0){
        // nottake=solve(index+1,1,arr);
        // }
        int ans = 0;

        // take current element
        ans = max(ans, arr[index] + solve(index + 1, sign, 1, arr, dp));

        // delete current element if not used
        if (!sign) {
            ans = max(ans, solve(index + 1, 1, 1, arr, dp));
        }

        return dp[index][sign][started] = ans;
    }

public:
    int maximumSum(vector<int>& arr) {
        vector<vector<vector<int>>> dp(
            arr.size(), vector<vector<int>>(2, vector<int>(2, 1e9)));
        return solve(0, 0, 0, arr, dp);
    }
};