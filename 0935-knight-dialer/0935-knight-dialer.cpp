class Solution {
    const int MOD = 1e9 + 7;

public:
    int knightDialer(int n) {
        if (n == 1)
            return 10;
        vector<vector<int>> jumps = { {4,6},{8, 6},    {7, 9}, {8, 4}, {3, 9, 0}, {},
                                     {1, 7, 0}, {6, 2}, {1, 3}, {4, 2}};

        vector<int> dp(10,1);
        for(int i=1;i<n;i++){
            vector<int> ndp(10,0);
            for(int k=0;k<10;k++){
                for(int j=0;j<jumps[k].size();j++){
                    int next=jumps[k][j];
                    ndp[next] = (ndp[next] + dp[k]) % MOD;
                }
            }
            dp=ndp;
        }
        int sum=0;
        for(int i=0;i<dp.size();i++){
            sum = (sum + dp[i]) % MOD;
        }
        return sum;
    }
};