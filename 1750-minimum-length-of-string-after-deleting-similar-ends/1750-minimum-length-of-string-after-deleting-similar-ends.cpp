class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start < end && s[start] == s[end]){
            char c = s[start];
            while(start <= end && s[start]==c){
                start++;
            }
            
            while(end>start && s[end]==c){
                end--;
            }
        }
        return end-start+1;
    }
};