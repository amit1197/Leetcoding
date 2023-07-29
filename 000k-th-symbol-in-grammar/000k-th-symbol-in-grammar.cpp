class Solution {
public:
    int kthGrammar(int n, int k) {
//         base case
        if(k==1 || n==1){
            return 0;
        }
//         recurrence relation
        int kParent = kthGrammar(n-1,(k-1)/2+1);
        
        int oddness=k%2;
        int ans=kParent?(oddness?1:0):(oddness?0:1);
        // cout<<"n "<<n<<" k "<<k<<"ans "<<ans<<endl;
        return ans;
        
        
        
        
        
    }
};