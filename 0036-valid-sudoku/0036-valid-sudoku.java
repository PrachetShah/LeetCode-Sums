class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0; i<9; i++){
            HashSet<Character> rows = new HashSet<>();
            HashSet<Character> cols = new HashSet<>();
            HashSet<Character> cube = new HashSet<>();
            
            for(int j=0; j<9; j++){
                // for rows
                if(board[i][j]!='.' && !rows.add(board[i][j])){
                    return false;
                }
                // for cols
                if(board[j][i]!='.' && !cols.add(board[j][i])){
                    return false;
                }
                // for squares
                int rowIndex = 3*(i/3);
                int colIndex = 3*(i%3);
                if(board[rowIndex + j/3][colIndex + j%3]!='.' && !cube.add(board[rowIndex + j/3][colIndex + j%3])){
                    return false;
                }
            }
        }
        return true;
    }

    /*
//     checking each row
    public static boolean valid_row(char[][] board){
        for(char[] row: board){
            if(!is_unit_valid(row)){
                return false;
            }
        }
        return true;
    }
    
    // checking each col 
    public static boolean valid_col(char[][] board){
        char[] col = new char[9];
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                col[j] = board[j][i];
            }
            if(!is_unit_valid(col)){
                return false;
            }
        }
        return true;
    }
    
    // checking each square in sudoku
    public static boolean valid_square(char[][] board){
        char[] square = new char[9];
        for(int i=0; i<3; i=i+3){
            for(int j=0; j<3; j=j+3){
                // looping inside 3 loop
                int index = 0;
                for(int row=i; row<i+3; row++){
                    for(int col=j; col<col+3; col++){
                        square[index] = board[row][col];
                        index++;
                    }
                }
                
                // checking if valid
                if(!is_unit_valid(square)){
                    return false;
                }
            }
        }
        return true;
    }
    
    public static boolean is_unit_valid(char[] arr){
        HashMap<Character, Boolean> check = new HashMap<>();
        for(int i=0; i<arr.length; i++){
            if(arr[i] != '.'){
                if(check.containsKey(arr[i])){
                    return false;
                }else{
                    check.put(arr[i], true);
                }
            }else{
                continue;
            }
        }
        return true;
    }
    */
}