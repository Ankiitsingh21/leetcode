class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
            unordered_map<int,int> mpp;
            int cnt=0;
        for(int i=0;i<A.size();i++){
            // unordered_map<int,int> mpp2;
            mpp[A[i]]++;
            if(mpp[A[i]]==2) cnt++;
            mpp[B[i]]++;
            if(mpp[B[i]]==2) cnt++;
            ans[i]=cnt;
        }
        return ans;
    }
};