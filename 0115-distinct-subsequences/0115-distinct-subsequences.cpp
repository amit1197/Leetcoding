class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long > > v(s.size(),vector<unsigned long long > (t.size()));
        if(s[0]==t[0]) v[0][0]=1;
        else v[0][0]=0;
        for(int i=1;i<t.size();i++) v[0][i]=0;
        for(int i=1;i<s.size();i++) 
        {
            if(s[i]==t[0]) v[i][0]=v[i-1][0]+1;
            else v[i][0]=v[i-1][0];
        }
        for(int i=1;i<s.size();i++)
        {
            for(int j=1;j<t.size();j++)
            {
                if(s[i]==t[j]) v[i][j] = v[i-1][j-1] + v[i-1][j];
                else v[i][j]=v[i-1][j];
            }
        }
        
        return v[s.size()-1][t.size()-1];
    }
};