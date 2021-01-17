class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n][5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<5;i++)dp[n-1][i]=1;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<5;j++){
                for(int k=j;k<5;k++){
                    dp[i][j]+=dp[i+1][k];
                }
            }
        }
        int ans=0;
        for(int i=0;i<5;i++){
            ans+=dp[0][i];
        }
        return ans;
    }
};