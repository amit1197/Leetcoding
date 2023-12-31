class Solution {
public:
    int numTrees(int n) {
        if(n==1)return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int r=1;r<=i;r++){
                dp[i]+=dp[r-1]*dp[i-r];
            }
        }
        
        return dp[n];
    }
};