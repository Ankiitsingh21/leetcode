class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum=0;
        int ones=0;
        for(int i=0;i<32;i++){
             ones=0;
            for(int &num:nums){
                int bit=(num>>i)&1;
                if(bit)ones++;
            }
            sum+=(ones*(nums.size()-ones));
        }
        return sum;
    }
};