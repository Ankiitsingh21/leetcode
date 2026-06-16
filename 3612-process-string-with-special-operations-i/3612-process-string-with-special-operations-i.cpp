class Solution {
public:
    string processStr(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                res+=s[i];
            }else if(s[i]=='*' && res.size()>0 ){
                // cout<<res[res.size()-1]<<" ";
                res.pop_back();
            }else if(s[i]=='#' && res.size()>0){
                res+=res;
            }else if(s[i]=='%' && res.size()>0){
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};