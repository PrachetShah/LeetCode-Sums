class Solution {
public:
    bool checkPalindrome(string word1, string word2){
        if(word1.length() != word2.length()){
            return false;
        }
        
        for(int i=0; i<word2.length(); i++){
            if(count(word2.begin(), word2.end(), word2[i]) != count(word1.begin(), word1.end(), word2[i])){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int i=1;
        while(i < words.size()){
            if(checkPalindrome(words[i], words[i-1])){
                // cout << words[i] << " "<< words[i-1] << endl;
                words.erase(words.begin() +i);
                // i++;
            }else{
                i++;
            }
        }
        return words;
    }
};