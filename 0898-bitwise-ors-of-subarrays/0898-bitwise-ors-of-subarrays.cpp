class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> st;
        unordered_set<int> prev;
        for(int i=0;i<arr.size();i++){
            // int orr=0;
            unordered_set<int> curr;
            curr.insert(arr[i]);
            for(int p:prev){
                curr.insert(p|arr[i]);
            }
            for(int x:curr){
                st.insert(x);
            }
            prev=curr;
            // cout<<orr<<" ";
        }
        return st.size();
    }
};