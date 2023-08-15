class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> dp;
        std::vector<int>:: iterator low1;
        for(int i=0;i<envelopes.size();i++){
            if(dp.size()==0){
                dp.push_back(envelopes[i][1]);
            }
            else{
                if(envelopes[i][1]>dp.back()){
                    dp.push_back(envelopes[i][1]);
                }
                else{
                    low1=std::lower_bound(dp.begin(),dp.end(),envelopes[i][1]);
                    int ind=low1-dp.begin();
                    dp[ind]=envelopes[i][1];
                }
            }
        }
        return dp.size();
    }
};