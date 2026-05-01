class Solution {
    vector<int> solve(int i,int j,string s,vector<vector<vector<int>>> &dp){
        if(!dp[i][j].empty()){
            return dp[i][j];
        }
      vector<int> ans;
        for(int k=i;k<j;k++){
           if(isdigit(s[k]))continue;
           vector<int> left=solve(i,k,s,dp);
           vector<int> right=solve(k+1,j,s,dp);

           for(int l=0;l<left.size();l++){
            for(int r=0;r<right.size();r++){
                 if (s[k] == '-') ans.push_back(left[l] - right[r]);
                    else if (s[k] == '*') ans.push_back(left[l] * right[r]);
                    else ans.push_back(left[l] + right[r]);
            }
           }
        }
        if (ans.empty()) {
            ans.push_back(stoi(s.substr(i, j - i)));
        }

        return dp[i][j]= ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.length();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1));
        return solve(0,expression.length(),expression,dp);
    }
};