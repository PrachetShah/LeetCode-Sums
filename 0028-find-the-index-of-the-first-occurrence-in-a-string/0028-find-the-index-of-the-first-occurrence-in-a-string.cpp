class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        for(int windowStart=0; windowStart<=n-m; windowStart++){
            for(int i=0; i<m; i++){
                if(needle[i] != haystack[windowStart+i]){
                    break;
                }
                if(i==m-1){
                    return windowStart;
                }
            }
        }
        return -1;
    }
};