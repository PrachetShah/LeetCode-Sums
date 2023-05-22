class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> m;
        for(auto num: nums){
            m[num]++;
        }
        
        priority_queue<pair<int,int>> p;
        
        for(auto it:m){
            p.push(make_pair(it.second, it.first));
            if(p.size() > (int)m.size()-k){
                ans.push_back(p.top().second);
                p.pop();
            }
        }
        return ans;
    }
};