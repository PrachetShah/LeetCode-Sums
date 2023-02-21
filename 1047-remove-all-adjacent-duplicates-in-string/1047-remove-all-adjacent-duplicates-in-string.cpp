class Solution {
public:
    string removeDuplicates(string s) {
        string a = "";
        for(int i=0; i<s.length(); i++){
            if(!a.empty() && a.back()==s[i]){
                a.pop_back();
            }else{
                a.push_back(s[i]);
            }
        }
        return a;
    }
};