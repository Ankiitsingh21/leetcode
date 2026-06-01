class Solution {
public:
    int minOperations(string s) {
        // string ans = "";
        // char ch = '0';
        // for (int i = 0; i < s.size(); i++) {
        //     ans.push_back(ch);
        //     if (ch == '0') {
        //         ch++;
        //     } else
        //         ch--;
        // }
        // int cnt = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     char ch = s[i];
        //     if (ch != ans[i]) {
        //         cnt++;
        //     }
        // }
        int cnt=0;
        char c='0';
        for(char ch:s){
            if(ch!=c) cnt++;
            if(c=='0') c++;
            else c--;
        }
        return min(cnt, ((int)s.size()-cnt));
    }
};