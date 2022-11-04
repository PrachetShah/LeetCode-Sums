class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='A' || c=='e' || c=='E' || c=='o' || c=='O' || c=='i' || c=='I' || c=='u' || c=='U';    
    }
    
    string reverseVowels(string s) {
        int start=0, end = s.size()-1;
        
        while(start < end){
            while(start < s.size()-1 && !isVowel(s[start])){
                start++;
            }
            
            while(end >= 0 && !isVowel(s[end])){
                end--;
            }
            
            if(start < end){
                swap(s[start++], s[end--]);
            }
        }
        return s;
    }
};