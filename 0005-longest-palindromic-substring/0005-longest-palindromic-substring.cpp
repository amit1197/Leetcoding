class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;

        }
        for(int i=s.size()-2;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    if((j-i) >1 ){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=1;
                    }
                }
                // cout<<"i:"<<i<<"j:"<<j<<":::"<<dp[i][j];        
            }
            // cout<<endl;
        }
        int ans=0;
        int inds=0;
        int inde=0;
        for(int i=0;i<s.size();i++ ){
            for(int j=i;j<s.size();j++){
                if(dp[i][j]==1) {
                    if((j-i+1) > ans){
                        ans=j-i+1;
                        inds=i;
                        inde=j;
                    }
                }
                // cout<<endl<<inds<<" "<<inde;

            }
        }
        return s.substr(inds,ans);

    }
};