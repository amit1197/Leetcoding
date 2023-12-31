class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1));
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();
        
        for(int i=0;i<dp[0].size();i++) dp[0][i]=i;
        for(int i=1;i<dp.size();i++) dp[i][0]=i;
        
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1] !=word2[j-1]) dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                else dp[i][j]=1+min(dp[i-1][j-1]-1,min(dp[i-1][j],dp[i][j-1]));
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};