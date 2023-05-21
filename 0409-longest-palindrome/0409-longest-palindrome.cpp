class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        int oddCount = 0;
        for(int i=0; i<s.length(); i++){
            m[s[i]]++;
            if(m[s[i]]%2 == 1){
                oddCount++;
            }else{
                oddCount--;
            }
        }
        if(oddCount > 1){
            return s.length()-oddCount+1;
        }
        return s.length();
    }
};