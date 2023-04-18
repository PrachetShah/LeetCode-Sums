class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size(), i=0;
        string result = "";
        while(len1 && len2){
            result.push_back(word1[i]);
            result.push_back(word2[i]);
            len1--;
            len2--;
            i++;
        }
        while(len1){
            result.push_back(word1[i]);
            i++;
            len1--;
        }
        while(len2){
            result.push_back(word2[i]);
            i++;
            len2--;
        }
        return result;
    }
};