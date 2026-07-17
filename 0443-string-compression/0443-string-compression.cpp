class Solution {
public:
    int compress(vector<char>& chars) {
       int i=0;
       vector<char> ans;
       while(i<chars.size()){
        char ch=chars[i];
        int cnt=0;
        while(i<chars.size() && chars[i]==ch){
            cnt++;
            i++;
        }
        ans.push_back(ch);
        if(cnt>1){
            string c=to_string(cnt);
            for(char &a:c){
                ans.push_back(a);
            }
        }
       }
       chars=ans;
       return ans.size();
    }
};