class Solution {
public:
    bool checkValidString(string s) {
        int i=0,mini=0,maxi=0;
        while(i<s.size()){
            if(s[i]=='('){
                mini=mini+1;
                maxi=maxi+1;
            }else if(s[i]==')'){
                mini=mini-1;
                maxi=maxi-1;
            }else{
                mini=mini-1;
                maxi=maxi+1;
            }
             if(mini<0){
                    mini=0;
                }
                if(maxi<0){
                    return false;
                }
            // cout<<mini<<" "<<maxi<<endl;
            i++;
        }
        if(mini==0 || maxi==0){
            return true;
        }
        return false;
    }
};