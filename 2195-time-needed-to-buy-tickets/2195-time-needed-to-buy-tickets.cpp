class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int ans=0;
        // cout<<ans;
        for(int i=0;i<t.size();i++){
            // if(i==k) continue;
            ans+=min(t[k]-(i>k),t[i]);
            cout<<" "<<min(t[k],t[i])<<" "<<ans<<" ";
        }
        return ans;
    }
};