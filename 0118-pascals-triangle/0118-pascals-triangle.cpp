class Solution {
    vector<int> solve(int row,vector<int> &anss){
        int ans=1;
        // vector<int> anss;
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
        vector<int> anss;
        for(int i=0;i<numRows;i++){
            ans.push_back(solve(i,anss));
            anss.clear();
        }
        return ans;
        // vector<vector<int>> ans;
        // for(int i=0;i<numRows;i++){
        //     vector<int> res;
        //     res.push_back(1);
        //     for(int j=1;j<i;j++){
        //         int val=ans[i-1][j-1]+ans[i-1][j];
        //         res.push_back(val);
        //     }
        //     if(i>=1) res.push_back(1);
        //     ans.push_back(res);
        //     // cout<<endl;
        // }
        // return ans;
    }
};