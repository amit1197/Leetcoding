class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> max_dp(nums.size());
        if(nums.size()==1){
            return nums[0];
        }
        else if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        else{
            max_dp[0]=nums[0];
            max_dp[1]=max(nums[1],nums[0]);
            for(int i=2;i<nums.size();i++)
            {
                max_dp[i]=max(max_dp[i-1],max_dp[i-2]+nums[i]);
            }
        }
        return max_dp[nums.size()-1];
    }
};