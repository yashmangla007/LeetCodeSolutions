class Solution {
public:

    void solve( int row, vector<string> &board, vector<vector<string>> &ans,
            vector<int> &sideColumn, vector<int> &rightDiagonal, vector<int> &leftDiagonal, int n){

                if(row == n){
                    ans.push_back(board);
                    return;
                }

                for(int col = 0; col<n; col++){

                    if( sideColumn[col]==0 && rightDiagonal[row+col]==0 &&
                        leftDiagonal[n-1 + col - row]==0 ){

                            board[row][col] = 'Q';
                            sideColumn[col] = 1;
                            rightDiagonal[row+col] = 1;
                            leftDiagonal[n-1 + col -row] = 1;

                            solve(row+1, board, ans, sideColumn, rightDiagonal, leftDiagonal, n);

                            board[row][col] = '.';
                            sideColumn[col] = 0;
                            rightDiagonal[row+col] = 0;
                            leftDiagonal[n-1 + col -row] = 0;

                        }

                }

            return;

            }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }

        vector<int> sideColumn(n,0) , rightDiagonal(2*n-1, 0) , leftDiagonal(2*n-1, 0);

        solve(0, board, ans, sideColumn, rightDiagonal, leftDiagonal, n);

        return ans; 
    }
};