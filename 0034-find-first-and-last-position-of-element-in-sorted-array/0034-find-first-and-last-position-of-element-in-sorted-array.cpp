class Solution {
public:
    int first(vector<int> arr, int target){
        int ans = -1;
        if(arr.size()==0){
            return ans;
        }
        int start = 0;
        int end = arr.size()-1;
        
        int mid = start + (end-start)/2;
        
        while(start <= end){
            if(arr[mid] == target){
                ans = mid;
                end = mid-1;
            }else if(target > arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
    int last(vector<int> arr,int target){
        int ans = -1;
        if(arr.size()==0){
            return ans;
        }
        int start = 0;
        int end = arr.size()-1;
        
        int mid = start + (end-start)/2;
        
        while(start <= end){
            if(arr[mid] == target){
                ans = mid;
                start = mid+1;
            }else if(target > arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> ans;
        // cout<<"First Index: "<<first(nums, target)<<endl;
        // cout<<"Last Index: "<<last(nums, target)<<endl;
        // ans.push_back(first(nums, target));
        // ans.push_back(last(nums, target));
        return {first(nums, target), last(nums, target)};
    }
};

// RECUSRIVE

// class Solution {
// public:
//     int first(vector<int> nums, int low, int high, int target){
//         int mid = low + (high-low)/2;
//         if(low > high)
//             return -1;
//         if(nums[mid] == target){
//             while(nums[mid]==target){
//                 mid = mid - 1;
//             }
//             return mid+1;
//         }
//         else if(nums[mid] > target)
//             return first(nums, low, mid-1, target);
//         else
//             return first(nums, mid+1, high, target);
//     }
    
//     int last(vector<int> nums, int low, int high, int target){
//         int mid = low + (high-low)/2;
//         if(low > high)
//             return -1;
//         if(nums[mid] == target){
//             while(nums[mid]==target){
//                 mid = mid + 1;
//             }
//             return mid-1;
//         }
//         else if(nums[mid] > target)
//             return last(nums, low, mid-1, target);
//         else
//             return last(nums, mid+1, high, target);
//     }
//     vector<int> searchRange(vector<int>& nums, int target) {
//         return {first(nums, 0, nums.size()-1, target), last(nums, 0, nums.size()-1, target)};
//     }
// };