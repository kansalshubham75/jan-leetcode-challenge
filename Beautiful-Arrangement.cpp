class Solution {
public:
    int dp[16][1<<16];
    int helper(int i,int mask,int n){
        if(i==n+1)return 1;
        if(dp[i][mask]!=-1)return dp[i][mask];
        dp[i][mask]=0;
        for(int num=1;num<=n;num++){
            if((num%i==0 || i%num==0) && (mask&(1<<num))==0){
                dp[i][mask]+=helper(i+1,(mask|(1<<num)),n);
            }
        }
        return dp[i][mask];
    }
    int countArrangement(int n) {
        for(int i=0;i<16;i++){
            for(int j=0;j<(1<<16);j++)dp[i][j]=-1;
        }
        return helper(1,0,n);
    }
};