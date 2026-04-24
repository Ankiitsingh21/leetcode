class Solution {
    const int MOD=1e9+7;
    pair<long long,long long> solve(int r,int c,vector<vector<int>> &grid,vector<vector<pair<long long,long long>>> &dp){
        if(r==0 && c==0) return {grid[r][c],grid[r][c]};

        if(dp[r][c].first != LLONG_MIN) return dp[r][c];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        if(r-1>=0){
            auto up=solve(r-1,c,grid,dp);

            long long a=up.first*grid[r][c];
            long long b=up.second*grid[r][c];


            maxi=max({maxi,a,b});
            mini=min({mini,a,b});
        }
        if(c-1>=0){
            auto left=solve(r,c-1,grid,dp);

            long long a=left.first*grid[r][c];
            long long b=left.second*grid[r][c]; 

            maxi=max({maxi,a,b});
            mini=min({mini,a,b});
        }
        return dp[r][c]={maxi,mini};
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {

        vector<vector<pair<long long,long long>>> dp(
    grid.size(),
    vector<pair<long long,long long>>(grid[0].size(), {LLONG_MIN, LLONG_MIN})
);
        auto res=solve(grid.size()-1,grid[0].size()-1,grid,dp);
        if(res.first<0) return -1;

        return res.first%MOD;
    }
};