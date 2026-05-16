class Solution {
    vector<int> solve(int index,string & s){
        vector<int> prefix(s.size()+1,0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                prefix[i+1]=prefix[i]+2;
            }else{
                prefix[i+1]=prefix[i];
            }
            prefix[i+1]=min(prefix[i+1],i+1);
        }
        return prefix;
    }
public:
    int minimumTime(string s) {
        vector<int> prefix=solve(0,s);
        reverse(s.begin(),s.end());
        vector<int> suffix=solve(0,s);
        reverse(suffix.begin(), suffix.end());
        int ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            ans=min(ans,prefix[i]+suffix[i]);
        }
        return ans;
    }
};