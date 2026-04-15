class Solution {
    int dfs(int index,string s,vector<int> &dp){
        if(index==s.size()) return 1;
        if(s[index]=='0') return 0;

        if(dp[index]!=-1){
            return dp[index];
        }
        int res=dfs(index+1,s,dp);

        
        if(index+1 <s.size()){
            if(s[index]=='1' || (s[index]=='2' && s[index+1] <'7' )){
                res+=dfs(index+2,s,dp);
            }
        }
        return dp[index]=res;
    }
public:
    int numDecodings(string s) {
         int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 1; 

        for(int index = n - 1; index >= 0; index--) {

            if(s[index] == '0') {
                dp[index] = 0;
                continue;
            }

            int res = dp[index + 1];

            if(index + 1 < n) {
                if(s[index] == '1' || 
                   (s[index] == '2' && s[index + 1] < '7')) {
                    res += dp[index + 2];
                }
            }

            dp[index] = res;
        }

        return dp[0];
    }
};