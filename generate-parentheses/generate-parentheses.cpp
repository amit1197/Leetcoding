class Solution {
public:
    void recur(string output,int open,int close,int i,int n,vector<string> &s)
    {
        if(i==2*n)
            s.push_back(output);
        if(open<n)
            recur(output+'(',open+1,close,i+1,n,s);
        if(open>close)
            recur(output+')',open,close+1,i+1,n,s);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        recur("",0,0,0,n,s);
        return s;
    }
};
