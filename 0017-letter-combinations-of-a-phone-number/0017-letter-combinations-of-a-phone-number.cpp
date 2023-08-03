class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> input;
        map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        for(int i=0;i<digits.size();i++)
        {
            input.push_back(m[digits[i] - '0']);
        }
        for(auto i:input) cout<<i<<" ";
        vector<string> ans;
        string st="";
        int level=0;
        if(digits.size()==0) return ans;
        solve(input,ans,st,level);
        return ans;
        
    }
    void solve(vector<string>& input,vector<string>& ans,string st,int level)
    {
        cout<<st<<" ";
        if(level==input.size())
        {
            cout<<st<<" ";
            ans.push_back(st);
            return;
        }
        for(int i=0;i<input[level].size();i++)
        {
            solve(input,ans,st + input[level][i],level+1);
        }
        return;
        
        
    }
};