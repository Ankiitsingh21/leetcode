class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        if(n<=8){
            ans+= n;
        }else if(n>8 && n<=16){
            ans+= 8+(2*(n-8));
        }else if(n>16 && n<=24){
            ans+= 8+(8*2)+(3*(n-16));
        }else{
            ans+=8+(8*2)+(8*3)+(4*(n-24));
        }
        return ans;

    }
};