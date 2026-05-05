class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(int &num:nums){
            xorr=xorr^num;
        }
        xorr=xorr&(-xorr);
        int a=0,b=0;
        for(int num:nums){
            if(xorr&num){
                a=a^num;
            }else{
                b=b^num;
            }
        }
        return {a,b};
    }
};