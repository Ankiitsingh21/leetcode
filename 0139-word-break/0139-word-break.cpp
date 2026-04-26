class Solution {
    bool solve(int index,string s,vector<string>& wordDict,vector<int> &dp){
        if(index==s.size()) return true;
        if(dp[index]!=-1) return dp[index];
        for(auto &w:wordDict){
            if(s.substr(index,w.length())==w){
                if(solve(index+w.length(),s,wordDict,dp)) return dp[index]= true;
            }
        }
        return  dp[index]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        // return solve(0,s,wordDict,dp);

        dp[s.size()]=true;
        for(int i=s.size()-1;i>=0;i--){
            for(auto &w:wordDict){
              if(s.substr(i,w.length())==w){
                 if(dp[i+w.length()]) {

                 dp[i]= true;
                 break;
                 } 
              }
            }
            //   dp[i]=false;
        }
        return dp[0];
    }
};