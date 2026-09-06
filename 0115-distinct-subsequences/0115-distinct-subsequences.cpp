class Solution {
public:
    int numDistinct(string str, string sub) {
        // vector<vector<int>> dp(str.size()+1,vector<int> (sub.size()+1,0));
        vector<long long> prev(sub.size()+1,0),curr(sub.size()+1,0);
	    prev[0]=1;
        const int MOD = 1e9 + 7;

	    for(int i=1;i<=str.size();i++){
            curr[0]=1;
	    	for(int j=1;j<=sub.size();j++){
	    		if(str[i-1]==sub[j-1]){
	            	 curr[j] = (prev[j - 1] + prev[j]) % MOD;
	            }
	            else{
	            	 curr[j]=prev[j];
	            }
	    	}
            prev=curr;
	    }
    
	    return prev[sub.size()];
    }
};