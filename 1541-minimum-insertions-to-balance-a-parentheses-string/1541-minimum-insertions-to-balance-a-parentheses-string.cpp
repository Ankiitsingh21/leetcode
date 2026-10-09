
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // Previous ')' cannot be left unmatched
                if (open > 0 && i > 0 && s[i - 1] == ')') {
                    // Handled by the closing-pair logic below
                }
                open++;
            } 
            else {
                // If next character is also ')', use both
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert one ')' to complete the pair
                    insertions++;
                }

                // Match this pair with an opening '('
                if (open > 0) {
                    open--;
                } 
                else {
                    // Insert an opening '('
                    insertions++;
                }
            }
        }

        // Each remaining '(' needs two ')'
        return insertions + 2 * open;
    }
};
