class Solution {
public:
    bool isSafe(int row, int col,  vector<vector<int>> &board, int n,
               map<int, bool> &rowCheck, map<int, bool> &lowDiag, map<int, bool> &upDiag){
        if(rowCheck[row]){
            return false;
        }

        // check diagonal
        if(lowDiag[row+col]){
            return false;
        }

        if(upDiag[n-1+col-row]){
            return false;
        }

        return true;
    }

    void addSolution(vector<vector<int>> &board, vector<vector<string>> &ans, int n){
        vector<string> row;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=0; j<n; j++){
                if(board[i][j]==1){
                    temp.push_back('Q');
                }else{
                    temp.push_back('.');
                }
                
            }
            row.push_back(temp);
        }

        ans.push_back(row);
    }


    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n,
              map<int, bool> &rowCheck, map<int, bool> &lowDiag, map<int, bool> &upDiag){
        if(col == n){
            addSolution(board, ans, n);
            return;
        }

        // solve 1 case, rest by recursion
        for(int row=0; row <n; row++){
            if(isSafe(row, col, board, n, rowCheck, lowDiag, upDiag)){
                board[row][col] = 1;
                rowCheck[row]=true, lowDiag[row+col]=true, upDiag[n-1+col-row]=true;
                solve(col+1, ans, board, n, rowCheck, lowDiag, upDiag);
                // backtracking
                board[row][col] = 0;
                rowCheck[row]=false, lowDiag[row+col]=false, upDiag[n-1+col-row]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int> (n, 0));
        // col
        map<int, bool> rowCheck;
        map<int, bool> lowDiag;
        map<int, bool> upDiag;
        // col
        solve(0, ans, board, n, rowCheck, lowDiag, upDiag);

        return ans;
    }
};