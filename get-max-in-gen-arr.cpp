class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<2)return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        int max_=1;
        for(int i=2;i<=n;i++){
            if(i%2){
                dp[i]=dp[i/2]+dp[(i/2)+1];
            }else{
                dp[i]=dp[i/2];
            }
            max_=max(max_,dp[i]);
        }
        return max_;
    }
};