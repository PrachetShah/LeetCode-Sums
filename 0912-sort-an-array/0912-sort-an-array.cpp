class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<nums.size(); i++){
            q.push(nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++){
            nums[i] = q.top();
            q.pop();
        }
        return nums;
    }
};