class Solution {
    int ExpandAndCount(string s,int i,int j){
        int cnt=0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            cnt+=ExpandAndCount(s,i,i);
            cnt+=ExpandAndCount(s,i,i+1);
        }
        return cnt;
    }
};