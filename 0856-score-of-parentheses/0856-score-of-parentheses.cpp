class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;
        st.push(0);   // base level score

        for(char c : s) {

            if(c == '(') {
                st.push(0);   // start new nested level
            }
            else {
                int v = st.top();   // score inside current ()
                st.pop();

                if(v == 0) {
                    // case "()"
                    st.top() += 1;
                }
                else {
                    // case "(A)"
                    st.top() += 2 * v;
                }
            }
        }

        return st.top();   // final score at base level
    }
};