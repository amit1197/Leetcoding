class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        solve(v,nums,0);
        return v;
    }
    void solve(vector<vector<int>>& v,vector<int>& nums,int pos)
    {
        if(pos >= nums.size())
        {
            v.push_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();i++)
        {
//             do
            swap(nums[pos],nums[i]);
//             recur
            solve(v,nums,pos+1);
//             undo
            swap(nums[pos],nums[i]);
        }
        
        
        
    }
};