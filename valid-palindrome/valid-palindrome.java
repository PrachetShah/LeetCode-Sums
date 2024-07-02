class Solution {
    public static boolean isValid(char ch){
        if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z') || (ch>='0' && ch<='9')){
            return true;
        }else{
            return false;
        }
    }
    
    public String buildString(String s){
        // create a var to store string to be checked
        StringBuilder temp = new StringBuilder();
            
        for(char ch: s.toCharArray()){
            if(isValid(ch)){
                if(Character.isUpperCase(ch)){
                    temp.append(Character.toLowerCase(ch));
                }else{
                    temp.append(ch);
                }
            }
        }
        return temp.toString();
    }
    
    public boolean isPalindrome(String s) {
        
        String fixed = buildString(s);
        int start = 0, end = fixed.length()-1;
        while(start < end){
            if(fixed.charAt(start) != fixed.charAt(end)){
                return false;
            }
            start++; end--;
        }
        return true;
    }
}