class Solution {
public:
    int reverse(int x) {
         long r=0;
         while(x){
            r=r*10 + x%10;
            x=x/10;
            cout<<r<<" "<<x<<" ";
         }
        if(r>INT_MAX || r<INT_MIN) return 0; // check range if r is outside the range then return 0  
        return int(r);
    }
};