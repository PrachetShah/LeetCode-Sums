class Solution:
    def isSafe(self, row, col, board, val):
        x,y = row,col
        
        for i in range(len(board)):
            if board[row][i] == val:
                return False
            if board[i][col] == val:
                return False
            if board[3*(row//3)+i//3][3*(col//3)+i%3] == val:
                return False
        return True
    
    def solve(self, board):
        vals = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
        for i in range(len(board)):
            for j in range(len(board)):
                if(board[i][j] == '.'):
                    for val in vals:
                        if(self.isSafe(i, j, board, val)):
                            board[i][j] = val
                            solveAhead = self.solve(board)
                            if(solveAhead):
                                return True
                            else:
                                board[i][j] = '.'
                    return False
        return True
                            
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.solve(board)
        