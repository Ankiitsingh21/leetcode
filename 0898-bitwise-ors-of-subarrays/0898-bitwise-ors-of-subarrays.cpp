class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> ans;
        for(int &x:arr){
            unordered_set<int> curr;
            curr.insert(x);
            for(int p:prev) curr.insert(p|x);
            for(int c:curr) ans.insert(c);
            prev=curr;
        }
        return ans.size();
    }
};