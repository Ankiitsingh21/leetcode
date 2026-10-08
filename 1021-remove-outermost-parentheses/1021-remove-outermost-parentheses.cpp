
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                // If already inside a primitive,
                // this '(' is not the outermost one.
                if (balance > 0) {
                    ans += c;
                }
                balance++;
            } 
            else {
                balance--;

                // If still inside, this ')' is not the outermost one.
                if (balance > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};