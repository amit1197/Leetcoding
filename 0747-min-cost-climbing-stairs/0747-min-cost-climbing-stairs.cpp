class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        
        dp[cost.size()]=INT_MAX;
        if(cost.size()==2) {
            return min(cost[0],cost[1]);
        }
        int i;
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(i=2;i<cost.size();i++) {
            dp[i]=min(dp[i-2],dp[i-1]) + cost[i];

        }
        return min(dp[i-1],dp[i-2]);


    }
};