class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int col=1;
        for(int i=1;i<=numRows;i++){
            vector<int> res;
            res.push_back(1);
            for(int j=2;j<i;j++){
                int val=ans[i-2][j-2]+ans[i-2][j-1];
                res.push_back(val);
            }
            if(i>1) res.push_back(1);
            ans.push_back(res);
            // cout<<endl;
        }
        return ans;
    }
};