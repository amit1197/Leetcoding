class Solution {
public:
    double myPow(double x, int n) {
        return helper(x,(long long)n);
        // if(n==0) return 1.0;
        // if(n<0) return 1.0/myPow(x,-n);
        // else {
        //     if(n%2){
        //         return myPow(x*x,n/2);
        //     }
        //     else{
        //         return x*myPow(x*x,(n-1)/2);
        //     }
        // }
    }
    double helper(double x, long long n) {
        if(n==0) return 1.0;
        if(n<0) return 1.0/helper(x,-1*n);
        else{
            if(n%2==0){
                return helper(x*x,n/2);
            }
            else{
                return x*helper(x*x,(n-1)/2);
            }
        }
    }
};
 