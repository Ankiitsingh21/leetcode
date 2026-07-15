class Solution {
    int gcd(int a,int b){
        while(b!=0){
            int rem=a%b;
            a=b;
            b=rem;
        }
        return a;
    }
public:
    int gcdOfOddEvenSums(int n) {
        int sumO=0;
        int sumE=0;
        for(int k=1;k<=n;k++){
            sumE+=2*k;
        }
        for(int k=1;k<=n;k++){
            sumO+=2*k-1;
        }
        return gcd(sumE,sumO);
    }
};