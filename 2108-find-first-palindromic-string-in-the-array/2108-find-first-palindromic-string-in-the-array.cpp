class Solution {
public:
    bool isPalindrome(string word){
        int  low=0, high=word.length()-1;
        
        while(low <= high){
            if(word[low] != word[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto word: words){
            if(isPalindrome(word)){
                return word;
            }
        }
        return "";
    }
};