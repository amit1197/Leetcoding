class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(),0);
        if(triangle.size()<2) return triangle[0][0];
        // cout<<"hello";
        dp[0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            // cout<<"h";
            for(int j=triangle[i].size()-1;j>=0;j--){
                // cout<<"e"<<"j"<<j<<"triangle[i].size()-1"<<triangle[i].size()-1;
                if(j==0){
                    dp[j]=dp[j]+triangle[i][j];
                    // cout<<"l";
                }
                else if(j==triangle[i].size()-1){
                    dp[j]=triangle[i][j]+dp[j-1];
                }
                else{
                    dp[j]=min(dp[j],dp[j-1]) + triangle[i][j];
                    // cout<<"o";
                }
            }
        }
        // cout<<endl;
        int ans=INT_MAX;
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
            ans=min(ans,dp[i]);
        }
        return ans;
    }
};