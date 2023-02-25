class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int startingRow=0, endingRow=rows-1, startingCol=0, endingCol =cols-1;
        
        int count=0, total=rows*cols;
        vector<int> ans;
        
        while(count < total){
            
            // print starting row
            for(int i=startingRow; count<total && i<=endingCol; i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            
            // print ending col
            for(int i=startingRow; count<total && i<=endingRow; i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int i=endingCol; count<total && i>=startingCol; i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            
            // print starting col
            for(int i=endingRow; count<total && i>=startingRow; i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};