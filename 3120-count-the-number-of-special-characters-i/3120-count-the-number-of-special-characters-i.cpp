class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<int> st;
        for(char &c:word){
            if(c>='A' && c<='Z'){
                int asci=(int)c;
                st.insert(asci+32);
            }
        }
        int cnt=0;
        for(char &c:word){
            if(c>='a'&&c<='z'){
                int asci=(int)c;
                if(st.find(asci)!=st.end()){
                    // cout<<c<<" ";
                    cnt++;
                    st.erase(asci);
                }
            }
        }
        return cnt;
    }
};