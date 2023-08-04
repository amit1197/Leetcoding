class Solution {
public:
    int maxDepth(string s) {
        int cur_depth =0;
        int max_depth=0;
        for(auto i:s){
            if(i=='('){
                cur_depth++;
            }
            if(i==')'){
                cur_depth--;
            }

            max_depth=max(max_depth,cur_depth);
        }
        return max_depth;
    }
};