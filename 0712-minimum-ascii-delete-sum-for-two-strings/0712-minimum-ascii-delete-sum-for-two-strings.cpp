class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1));
//         filling the rightmost-bottomost element.
        dp[s1.size()][s2.size()]=0;
//         filling the last row
        for(int i=s2.size()-1;i>=0;i--)
        {
            dp[s1.size()][i]=dp[s1.size()][i+1] + int(s2[i]);
        }
//         filling the last column
        for(int i=s1.size()-1;i>=0;i--)
        {
            dp[i][s2.size()]=dp[i+1][s2.size()] + int(s1[i]);
        }
//         filling remaining grid
        for(int i=s1.size()-1;i>=0;i--)
        {
            for(int j=s2.size()-1;j>=0;j--)
            {
//                 case1: if s1[i]==s2[j]
                if(s1[i]==s2[j])
                {
                    dp[i][j]=dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=min(int(s2[j]) + dp[i][j+1] , int(s1[i]) + dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};