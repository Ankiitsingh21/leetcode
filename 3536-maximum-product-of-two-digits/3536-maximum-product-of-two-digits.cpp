class Solution {
public:
    int maxProduct(int n) {
        int maxi=0;
        int secondMaxi=0;
        while(n>0){
            int digit=n%10;
            // cout<<digit<<" ";
            if(digit>=maxi){
                secondMaxi=maxi;
                maxi=digit;
            }
            else if(digit>secondMaxi){
                secondMaxi=digit;
            }
            // cout<<digit<<" "<<maxi<<" "<<" "<<secondMaxi<<endl;; 
            n/=10;
        }
        return  maxi*secondMaxi;
    }
};