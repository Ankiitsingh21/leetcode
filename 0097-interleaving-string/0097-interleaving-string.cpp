class Solution {
    bool solve(int i,int j,int k,string s1,string s2,string s3 , vector<vector<int>> &dp){
        if(k==s3.size() && i==s1.size() && j==s2.size() ) return true;
        if(k==s3.size() && (i!=s1.size() || j!=s2.size() )) return false;


        if(dp[i][j] !=-1) return dp[i][j];
        if(s1[i]!=s3[k] && s2[j]!=s3[k]) return false;


        if(s1[i]==s3[k] && s2[j]!=s3[k]){
            return dp[i][j] = solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(s2[j]==s3[k] && s1[i]!=s3[k]){
            return dp[i][j] = solve(i,j+1,k+1,s1,s2,s3,dp);
        }


        bool sa=solve(i+1,j,k+1,s1,s2,s3,dp);
        bool sb=solve(i,j+1,k+1,s1,s2,s3,dp);

        return dp[i][j] = sa||sb;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        // return solve(0,0,0,s1,s2,s3,dp);
        int size1=s1.size();
        int size2=s2.size();
        int size3=s3.size();
        if(size1+size2 != size3) return false;

        dp[size1][size2]=true;
        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                // for(int k=s3.size()-1;k>=0;k--){
                    int k = i + j;

                if (i < size1 && s1[i] == s3[k]) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j];
                }

                if (j < size2 && s2[j] == s3[k]) {
                    dp[i][j] = dp[i][j] || dp[i][j + 1];
                }
                // }  
            }
        }
        return dp[0][0];
    }
};