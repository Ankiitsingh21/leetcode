class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(i);
            }else{
                if(
                    st.size()>1 &&
                    (
                        (s[i]==')' && s[st.top()]=='(') ||
                        (s[i]==']' && s[st.top()]=='[') ||
                        (s[i]=='}' && s[st.top()]=='{') 
                    )
                ){
                    st.pop();
                    maxLen=max(maxLen,i-st.top());
                }else{
                    st.push(i);
                }
            }
        }
        return maxLen;
    }
};