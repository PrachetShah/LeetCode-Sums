class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int len = s.length(), i;
        map<char, int> one;
        map<char, int> two;
        for(i=0; i<len; i++){
            one[s[i]]++;
            two[t[i]]++;
        }
        // for(i=0; i<len; i++){
        //     if(one[s[i]] != two[s[i]]){
        //         return false;
        //     }
        // }
        if(one == two){
            return true;
        }else{
            return false;
        }
        // return true;
    }
};