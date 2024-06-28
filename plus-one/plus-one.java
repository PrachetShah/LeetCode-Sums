class Solution {
    public int[] plusOne(int[] digits) {
        for(int i=digits.length-1; i>=0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        int[] out = new int[digits.length+1];
        out[0] = 1;
        return out;
        
        
        /*
        MY INITIAL SOL
        if(digits[digits.length-1] < 9){
            digits[digits.length-1]++;
            return digits;
        }else{
            int increment = digits.length-1;
            while(increment>=0 && digits[increment] == 9){
                digits[increment] = 0;
                increment--;
            }
            // if increment is greater than 1 than add one else add 1 in beginnning
            if(increment >= 0){
                digits[increment]++;
                return digits;
            }else{
//                 if here it means that number has 1 in start, and 0 everywhere
                int[] res = new int[digits.length+1];
                res[0] = 1;
                return res;
            }

        }
        */
    }
}