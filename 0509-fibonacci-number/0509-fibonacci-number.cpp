class Solution {
public:
    int fib(int n) {
        int curr=0, prev = 1;
        for(int i=0; i<n; i++){
            int temp = curr;
            curr = curr + prev;
            prev = temp;
        }
        return curr;
    }
};