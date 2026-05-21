class Solution {
public:
    int countDigits(int num) {
        int n=num;
        int cnt=0;
        while(num>0){
            int digit=num%10;
            if(n%digit==0)cnt++;
            num=num/10;
        }
        return cnt;
    }
};