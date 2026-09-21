class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int i = 0;
        for (char c : s) {
            int rev = 26 - (c - 'a');
            ans += rev * (i + 1);
            i++;
        }
        return ans;
    }
};