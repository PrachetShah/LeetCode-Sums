class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        int table[n+1][m+1];
        table[0][0] = 0;
        
        for(int i=1; i<=n; i++){
            table[i][0] = i;
        }
        for(int j=1; j<=m; j++){
            table[0][j] = j;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(word1[i-1] == word2[j-1]){
                    table[i][j] = table[i-1][j-1];
                }else{
                    int curr = min(table[i-1][j], table[i][j-1]);
                    table[i][j] = min(curr, table[i-1][j-1])+1;
                }    
            }
        }
        return table[n][m];
    }
};