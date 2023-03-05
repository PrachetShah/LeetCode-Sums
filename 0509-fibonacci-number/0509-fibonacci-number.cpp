class Solution {
public:
//     RECURSIVE SLOW
//     int fib(int n){
//         if(n==0)
//             return 0;
        
//         if(n==1)
//             return 1;
        
//         return fib(n-1) + fib(n-2);
//     }
//     ITERATIVE FAST
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