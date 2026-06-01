class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int x:row){
            for(int j=0;j<matrix[x].size();j++){
                matrix[x][j]=0;
            }
        }
        for(int x:col){
            for(int i=0;i<matrix.size();i++){
                matrix[i][x]=0;
            }
        }
        return ;
    }
};