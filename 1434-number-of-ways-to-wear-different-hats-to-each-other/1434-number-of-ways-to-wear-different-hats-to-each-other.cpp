class Solution {
    int solv(int index,vector<vector<int>> &hats,vector<int> &vis){
        if(index==hats.size()){
            return 1;
        }

        int cnt=0;
        for(int i=0;i<hats[index].size();i++){
            if(vis[hats[index][i]]==0){
                vis[hats[index][i]]=1;
                cnt+=solv(index+1,hats,vis);
                vis[hats[index][i]]=0;
            }
        }
        return cnt;
    }
    int solve(int hat,vector<vector<int>> &vis,int mask,int n,vector<vector<int>> &dp){
        if(mask==((1<<n)-1)) return 1;
        if(hat>40) return 0;
        if(dp[hat][mask]!=-1) return dp[hat][mask];
        int ways=solve(hat+1,vis,mask,n,dp);

        for(int person:vis[hat]){
            if(mask&(1<<person)) continue;
            ways = (ways + solve(hat+1,vis, mask|(1<<person),n,dp)) % (int)(1e9+7);
        }
        return dp[hat][mask]=ways;
    }
public:
    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> vis(41);
        for(int i=0;i<hats.size();i++){
            for(int x:hats[i]){
                vis[x].push_back(i);
            }
        }
        vector<vector<int>> dp(41,vector<int>(1<<10,-1));
        int n=hats.size();
        // vector<int> vis(41,0);
        return solve(1,vis,0,n,dp);
    }
};