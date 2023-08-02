class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[i].size();j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(j==0){
                    matrix[i][j]+=min(matrix[i-1][j+1],matrix[i-1][j]) ;
                }
                else if(j==matrix[i].size()-1){
                    matrix[i][j]+=min(matrix[i-1][j-1],matrix[i-1][j]);
                }
                else{
                    matrix[i][j]+=min(min(matrix[i-1][j-1],matrix[i-1][j]) , matrix[i-1][j+1]);
                }
            }
        }
        // cout<<"------------"<<endl;
        int ans=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                // cout<<matrix[i][j]<<" ";
                if(i==matrix.size()-1)
                    ans=min(ans,matrix[i][j]);
            }
            // cout<<endl;
        }
        return ans;
    }
};