class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int grossTrade=0;
        int currTrade=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0){
                currTrade+=prices[i]-prices[i-1];
            }
            else{
                grossTrade+=currTrade;
                currTrade=0;
            }
        }
        grossTrade+=currTrade;
        return grossTrade;
    }
};