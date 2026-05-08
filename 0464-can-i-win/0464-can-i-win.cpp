class Solution {
    unordered_map<int,bool> mpp;
    bool solve(int used,int maxi,int total){
        if(total<=0) return false;
        if(mpp.find(used)!=mpp.end()) return mpp[used];
        for(int i=1;i<=maxi;i++){
            if((used>>i)&1) continue;

            if(!solve((used|(1<<i)),maxi,total-i)) return mpp[used]=true;
        }
        return mpp[used]=false;
    }
public:
    bool canIWin(int maxi, int total) {
        //iftotal can be less then or equal to 0
        if(total<=0) return true;
        int sum=(maxi*(maxi+1))/2;

        if(sum<total) return false;

        return solve(0,maxi,total);
    }
};