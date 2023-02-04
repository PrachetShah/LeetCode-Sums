class Solution {
public:
    bool areVectorEq(vector<int> a1, vector<int> a2){
        for(int i=0; i<26; i++){
            if(a1[i] != a2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        
        vector<int> s1map(26, 0);
        for(auto s: s1){
            s1map[s-'a']++;
        }
        
        vector<int> s2map(26, 0);
        
        int i=0, j=0;
        
        while(j<s2.size()){
            s2map[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                if(areVectorEq(s1map, s2map))
                    return true;
            }
            
            if(j-i+1< s1.size())
                j++;
            else{
                s2map[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};