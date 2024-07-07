class Solution {
    public int myAtoi(String s) {
        int res = 0;
        boolean isPositive = true;
        
        int len = s.length();
        int index = 0;
        
        while(index < len && s.charAt(index)==' '){
            index++;
        }
        
        if(index < len){
            if(s.charAt(index)=='-'){
                isPositive = false;
                index++;
            }else if(s.charAt(index)=='+'){
                index++;
            }
        }
        
        while(index<len && s.charAt(index)>='0' && s.charAt(index)<='9'){
            int digit = s.charAt(index) - '0';
      
          // to avoid integer overflow
          if (res > (Integer.MAX_VALUE / 10) || (res == (Integer.MAX_VALUE / 10) && digit > 7)){
              return isPositive ? Integer.MAX_VALUE : Integer.MIN_VALUE;
          }

          // adding digits at their desired place-value
          res = (res * 10) + digit;

          ++index;
        }
        
        
        
        return isPositive ? res : -res;
    }
}