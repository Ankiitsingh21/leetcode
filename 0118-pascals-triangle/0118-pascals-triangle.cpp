class Solution {
    vector<int> solve(int row){
        int ans=1;
        vector<int> anss;
        anss.push_back(1);
        for(int i=1;i<=row;i++){
            ans=ans*(row-i+1);
            ans=ans/i;
            anss.push_back(ans);
        }
        return anss;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};