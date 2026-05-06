class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<vector<int>>st;
        int l=0,r=k;
        while(r<=s.size()){
            vector<int> si(k);
            for(int i=l;i<r;i++){
                si[i-l]=s[i]-'0';
            }
            if(st.find(si)==st.end()){
                st.insert(si);
            }
            l++;
            r++;
        }
        return st.size()==(1<<k)?true:false;
    }
};