class Solution {
public:
    vector<int> merge(vector<int> left, vector<int> right){
        vector<int> ans;
        
        int leftPoint = 0, rightPoint = 0;
        while(leftPoint < left.size() && rightPoint < right.size()){
            if(left[leftPoint] > right[rightPoint]){
                ans.push_back(right[rightPoint]);
                rightPoint++;
            }else{
                ans.push_back(left[leftPoint]);
                leftPoint++;
            }
        }
        
        while(leftPoint < left.size()){
            ans.push_back(left[leftPoint]);
            leftPoint++;
        }
        while(rightPoint < right.size()){
            ans.push_back(right[rightPoint]);
            rightPoint++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = merge(nums1, nums2);
        
        // for(auto num: merged){
        //     cout << num << " ";
        // }
        // cout << endl << mid << endl;
        
        int mid = ceil(merged.size()/2);
        
        if(merged.size()%2 == 0){
            return (double)(merged[mid-1] + merged[mid])/2;
        }else{
            return merged[mid];
        }
    }
};