class Solution {
    int solve(int cnt,int paste,int n){
        if(cnt==n) return 0;
        if(cnt>n) return 1000;

        //paste
        int past=1+solve(cnt+paste,paste,n);

        //copy & paste

        int cp=2+solve(cnt+cnt,cnt,n);


        return min(cp,past);
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        return 1+solve(1,1,n);
    }
};