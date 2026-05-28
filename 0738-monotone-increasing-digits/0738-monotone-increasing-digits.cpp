class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int mark = -1;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] > s[i + 1]) {
                mark = i;
                break;
            }
        }
        if (mark == -1)
            return n;
        while(mark>0 && s[mark]==s[mark-1]) mark--;
        s[mark]--;
        for (int i = mark + 1; i < s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};