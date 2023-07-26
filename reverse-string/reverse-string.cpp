class Solution {
public:
    void reverseString(vector<char>& s) {
        int f=0;
        int l=s.size()-1;
        revString(s,f,l);
        return;
    }
    void revString(vector<char>& s,int f,int l){
        if(f==l || f>l){
            return;
        }
        char temp=s[f];
        s[f]=s[l];
        s[l]=temp;
        revString(s,f+1,l-1);
    }
    
};