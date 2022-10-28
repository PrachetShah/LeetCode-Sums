class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        
        unordered_map<string, vector<string>>mp;
        
        for(auto i: strs){
            string s = i;
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        
        // now simply put the elements  of second column of map in ans
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};