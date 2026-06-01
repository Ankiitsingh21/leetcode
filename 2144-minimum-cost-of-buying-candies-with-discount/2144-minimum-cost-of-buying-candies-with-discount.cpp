class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum=0;
        sort(cost.begin(),cost.end(),[](const auto &a,const auto &b){
            return a>b;
        });
        int cnt=0;
        for(int i=0;i<cost.size();i++){
            if(cnt<2){
                sum+=cost[i];
                cnt++;
            }else{
                cnt=0;
            }
        }
        return sum;
    }
};