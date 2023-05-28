class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int len = s.length();
        map<char, int> counts;
        for(int i=0; i<len; i++){
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for(auto count: counts){
            if(count.second){
                return false;
            }
        }
        return true;
        
        
//         int len = s.length(), i;
//         map<char, int> one;
//         map<char, int> two;
//         for(i=0; i<len; i++){
//             one[s[i]]++;
//             two[t[i]]++;
//         }
        
// //         M1
//         if(one == two){
//             return true;
//         }else{
//             return false;
//         }
// //         M2
//         // for(i=0; i<len; i++){
//         //     if(one[s[i]] != two[s[i]]){
//         //         return false;
//         //     }
//         // }
        
//         // return true;
    }
};