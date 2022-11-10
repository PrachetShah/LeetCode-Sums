class Solution {
public:
    string removeDuplicates(string s) {
        string a = "";
        stack<char>st; 
        for(int i = 0; i < s.size(); i++){
            if(!a.empty() && a.back() == s[i]){
                a.pop_back();
            } else {
                 a+=s[i];
            }
        }
        return a;
    }
};