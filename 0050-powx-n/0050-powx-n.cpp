class Solution {
public:
    double myPow(double x, int N) {
        long long n=N;
        if(n<0){
            x=1/x;
            n=-n;
        }
        double ans=1;
        // for(long long i=1;i<=n;i++){
        //     ans*=x;
        // }
        while(n>0){
            if(n%2==1){
                ans*=x;
                n--;
            }else{
                x*=x;
                n/=2;
            }
        }
        return ans;
    }
};