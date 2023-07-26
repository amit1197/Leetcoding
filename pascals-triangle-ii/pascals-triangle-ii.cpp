class Solution {
public:
    // vector<int> getRow(int rowIndex) {
    //     vector<int> row(rowIndex+1);
    //     return helper(row,rowIndex+1);
    // }
    // vector<int> helper(vector<int>& row,int r){
    //     row[0]=1;
    //     row[r-1]=1;
    //     for(int i=1;i<r-1;i++){
    //         row[i]=pascal(r,i+1);
    //     }
    //     return row;
    // }
    // int pascal(int i,int j){
    //     if(j==1 || i==j) return 1;
    //     return pascal(i-1,j-1) + pascal(i-1,j);
    // }
    
    vector<int> getRow(int rowIndex) {
//         base case
        if(rowIndex==0) return {1};
        vector<int> currRow={1};
        vector<int> prevRow=getRow(rowIndex-1);
        for(int i=1;i<rowIndex;i++){
            currRow.push_back(prevRow[i-1] + prevRow[i]);
            
        }
        currRow.push_back(1);
        return currRow;
    }
};