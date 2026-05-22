class Solution {
public:
    double myPow(double x, int N) {
        long long n=N;
      double ans=1;
        if(N<0){
            x=1/x;
            n=-n;
        }
    //   while(n>0){
    //     if(n%2==1){
    //         ans*=x;
    //         n--;
    //     }else{
    //         n/=2;
    //         x*=x;
    //     }
    //   } 
    // for(long long i=1;i<=n;i++){
    //     ans*=x;
    // }
    while(n>0){
        if(n%2==1){
            ans*=x;
            n--;
        }else{
            n/=2;
            x*=x;
        }
    }
      return ans;
    }
};