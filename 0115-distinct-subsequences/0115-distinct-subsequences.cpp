class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<pair<unsigned long long,unsigned long long>>> dp(s.size()+1,      vector<pair<unsigned long long,unsigned long long>>(t.size()+1, make_pair(0,1)));
        for(int i=0;i<dp.size();i++){
            dp[i][0]=make_pair(0,1);
        }
        for(int i=0;i<dp[0].size();i++){
            dp[0][i]=make_pair(0,1);
        }
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(s[i-1]==t[j-1]){
                    unsigned long long x=0;
                    unsigned long long y=0;
                    unsigned long long xa=dp[i-1][j-1].first+1;
                    unsigned long long ya=dp[i-1][j-1].second;
                    unsigned long long xb=dp[i-1][j].first;
                    unsigned long long yb=dp[i-1][j].second;
                    unsigned long long xc=dp[i][j-1].first;
                    unsigned long long yc=dp[i][j-1].second;
                    x=max(max(xa,xb),xc);
                    // x=xa+1;
                    if(xa==x) y+=ya;
                    if(xb==x) y+=yb;
                    if(xc==x) y+=yc;
                    dp[i][j]=make_pair(x,y);
                }
                else{
                    unsigned long long x=0;
                    unsigned long long y=0;
                    unsigned long long xb=dp[i-1][j].first;
                    unsigned long long yb=dp[i-1][j].second;
                    unsigned long long xc=dp[i][j-1].first;
                    unsigned long long yc=dp[i][j-1].second;
                    x=max(xb,xc);
                    if(xb>xc){
                        y=yb;
                    }
                    else if(xb<xc){
                        y=yc;
                    }
                    else{
                        y=max(yb,yc);
                    }
                    dp[i][j]=make_pair(x,y);

                }
            }
        }
        
        return dp[s.size()][t.size()].first<t.size()?0:dp[s.size()][t.size()].second;
    }
};