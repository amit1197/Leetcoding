class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        vector<int> dp;
        vector<int> ans(o.size(),1);
        std::vector<int>::iterator upper1,lower1;
        dp.push_back(o[0]);
        for(int i=1;i<o.size();i++){
            if(o[i]>=dp.back()){
                dp.push_back(o[i]);
                ans[i]=dp.size();
            }
            else{
                upper1=std::upper_bound(dp.begin(),dp.end(),o[i]);
                int index=upper1-dp.begin();
                dp[index]=o[i];
                ans[i]=index+1;

            }
            
            


        }
        return ans;

    }
};