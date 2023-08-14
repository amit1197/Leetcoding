class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]-d)!=m.end()){
                m[nums[i]]=max(m[nums[i]-d]+1,m[nums[i]]);
            }
            else{
                m[nums[i]]=1;
            }
        }
        int res=0;
        for(auto i:m){
            res=max(res,i.second);
        }
        return res;
    }
};