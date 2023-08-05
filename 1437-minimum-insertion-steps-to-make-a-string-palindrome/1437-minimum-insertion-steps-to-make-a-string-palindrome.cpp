class Solution {
public:
    int minInsertions(string s) {
        int r= lps(s);
        // cout<<r<<endl;
        return s.size()-r;
    }
    int lps(string s){
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
        }
        for(int i=s.size()-2;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return dp[0][s.size()-1];
    }
};