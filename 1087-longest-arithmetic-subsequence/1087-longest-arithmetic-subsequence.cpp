class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // vector<map<int,int>> dp(nums.size());
        vector<vector<int>> dp(nums.size(),vector<int>(1002,0));
        // map<int,int> m0;
        // m0[0]=1;
        // dp[0]=m0;
        dp[0][0]=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                // cout<<"h";
                int d=nums[i]-nums[j];
                d+=500;
                // cout<<d<<" ";
                // map<int,int> m=dp[j];
                // if(m.find(d)!=m.end()){
                if(dp[j][d]!=0){    
                    dp[i][d]=max(dp[i][d],dp[j][d]+1);
                    // dp[i][d]=m[d]+1;
                }
                else{
                    dp[i][d]=max(dp[i][d],2);
                }
                // cout<<"e";
            }
            // map<int,int> mp=dp[i];
            // for(auto i:mp){
            //     ans=max(ans,i.second);
            // }
            for(int i:dp[i]){
                // cout<<"d";
                ans=max(ans,i);
            }
            // cout<<"f";
        }
        // cout<<"h";
        return ans;
    }
};