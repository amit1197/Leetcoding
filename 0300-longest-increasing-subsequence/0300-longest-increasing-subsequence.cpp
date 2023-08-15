class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        std::vector<int>::iterator low1;
        for(int i=0;i<nums.size();i++){
            if(dp.size()==0){
                dp.push_back(nums[i]);
            }
            else{
                if(nums[i]>dp.back()){
                    dp.push_back(nums[i]);
                }
                else{
                    low1 = std::lower_bound(dp.begin(), dp.end(), nums[i]);
                    int index=low1-dp.begin();
                    dp[index]=nums[i];
                }

            }
        }
        return dp.size();
    }
};