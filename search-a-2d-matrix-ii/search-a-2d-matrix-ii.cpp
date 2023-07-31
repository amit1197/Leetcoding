class Solution {
public:
    int m = 0;
    int n = 0;
    
    bool recurse(vector<vector<int>>& matrix, int ib, int je, int x){
        if(ib>=m || je<0){
            return false;
        }
        
        while(matrix[ib][je] < x){
            ib++;
            if(ib>=m)
                return false;
        }
        if(matrix[ib][je] == x)
            return true;
        while(matrix[ib][je] > x){
            je--;
            if(je < 0)
                return false;
        }
        
        return recurse(matrix,ib,je,x);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // dfs(0,m-1,0,n-1) -> dfs(i+1,m-1,0,j-1)
        
        m = matrix.size();
        n = matrix[0].size();
        return recurse(matrix,0,n-1,target);
    }
};