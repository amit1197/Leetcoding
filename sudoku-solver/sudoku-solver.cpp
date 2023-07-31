class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        func(board);
    }
    bool func(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){ // figure out the first empty cell
                    for(char c='1';c<='9';c++){ // try out every integer
                        if(isValid(board,i,j,c)){ // check all the 3 conditions
                            board[i][j]=c;
                            if(func(board)) return true; // again the recursion call went 
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true; // i have filled everything that's why i came to this line
    }
    bool isValid(vector<vector<char>> &board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) return false; // check for entire column
            if(board[row][i]==c) return false; // check for every row
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false; // check for entire box
        }
        return true;
    }
};