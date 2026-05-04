class Solution {
public:
    int reverseBits(int n) {
        vector<int> store;
        for(int i=31;i>=0;i--){
            int a=((n>>i)&1);
            store.push_back(a);
        }
        // for(int i=0;i<store.size();i++){
        //     cout<<store[i];
        // }
        reverse(store.begin(),store.end());
        long long result=1;
        for(int i=0;i<32;i++){
            result=result*2+store[i];
        }
        return result;
    }
};