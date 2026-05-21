class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        // int mul=1;
        set<int> st;
        for(int &num:nums){
            //  int cnt=0;
             for(int i=2;i*i<=num;i++){
                 if(num%i==0){
                    st.insert(i);
                    //  cnt++;
                     while(num%i==0) num=num/i;
                 }
             }
             if(num>1) st.insert(num);
            //  return cnt;
        }
        return st.size();
    }
};