class Solution {
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y) return false;
        return target % gcd(x, y) == 0;
    }
};