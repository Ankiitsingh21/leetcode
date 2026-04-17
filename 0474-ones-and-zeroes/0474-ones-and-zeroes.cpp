class Solution {
    int one(string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
            }
        }
        return cnt;
    }
    int zero(string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cnt++;
            }
        }
        return cnt;
    }
    int solve(int m,int n,int o,int z,vector<string>&strs,int index,vector<vector<vector<int>>> &dp){
        if(dp[index][z][o]!=-1) return dp[index][z][o];
        int ones=one(strs[index]);
        int zeros=zero(strs[index]);
        if(index==0){
            if(z+zeros<=m && o+ones<=n){
                return 1;
            }else{
                return 0;
            }
        }


        int take=0;
        if(o+ones<=n && z+zeros<=m){
            take=1+solve(m,n,o+ones,z+zeros,strs,index-1,dp);
        }
        int nottake=solve(m,n,o,z,strs,index-1,dp);

        return dp[index][z][o]=max(take,nottake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(m,n, 0,0,strs,strs.size()-1,dp);
        
    }
};