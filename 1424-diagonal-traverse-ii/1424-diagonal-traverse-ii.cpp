class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> groups;
        
        for(int row=nums.size()-1; row>=0; row--){
            for(int col=0; col<nums[row].size(); col++){
                groups[row+col].push_back(nums[row][col]);
            }
        }
        
        vector<int> ans;
        int curr = 0;
        while(groups.find(curr) != groups.end()){
            for(auto num: groups[curr]){
                ans.push_back(num);
            }
            curr++;
        }
        
        return ans;
    }
};