class Solution {
    bool monotonic(int n){
        int last=10;
        while(n>0){
            int digit=n%10;
            if(digit>last){
                return false;
            }
            last=digit;
            n=n/10;
        }
        return true;
    }
     int smartDecrease(int n){ 
        string s=to_string(n);
        int mark=-1;
        for(int j=0;j<s.size()-1;j++){
            if(s[j]>s[j+1]) mark=j;
        }
        while(mark>0 && s[mark-1]==s[mark]) mark--;
        s[mark]--;
        for(int j=mark+1;j<s.size();j++) s[j]='9';
        return stoi(s);
    }
public:
    int monotoneIncreasingDigits(int n) {
        while(n>0){
            if(monotonic(n)){
                return n;
            }
            n=smartDecrease(n);
        }
        return 0;
    }
};