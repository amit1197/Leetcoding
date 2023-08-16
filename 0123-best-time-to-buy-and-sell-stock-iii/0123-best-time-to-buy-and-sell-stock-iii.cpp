class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> s0(n,0);
        vector<int> s1(n,0);
        vector<int> s2(n,0);
        vector<int> s3(n,0);
        vector<int> s4(n,0);
        // base case
        s0[0]=0;
        s1[0]=-1*prices[0];
        s2[0]=0;
        s3[0]=-1*prices[0];
        s4[0]=0;
        for(int i=1;i<n;i++){
            s0[i]=0;
            s1[i]=max(s1[i-1],s0[i-1]-prices[i]);
            s2[i]=max(s2[i-1],s1[i-1]+prices[i]);
            s3[i]=max(s3[i-1],s2[i-1]-prices[i]);
            s4[i]=max(s4[i-1],s3[i-1]+prices[i]);
        }
        return max(s2[n-1],s4[n-1]);
    }
};