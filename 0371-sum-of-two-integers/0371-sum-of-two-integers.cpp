class Solution {
public:
    int getSum(int a, int b) {
        int res=0;
        int carry=0;
        for(int i=0;i<32;i++){
            int abit=(a>>i)&1;
            int bbit=(b>>i)&1;
            int bitt = abit ^ bbit ^ carry;
            carry=(abit & bbit) | (carry & (abit ^ bbit));
            if(bitt){
                res=res|(1<<i);
            }
        }
        return res;
    }
};