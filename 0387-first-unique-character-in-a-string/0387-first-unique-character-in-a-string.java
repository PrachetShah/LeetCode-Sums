class Solution {
    public int firstUniqChar(String s) {
        // using hashMap
        Map<Character, Integer> count = new HashMap<>();
        for(char ch: s.toCharArray()){
            if(count.containsKey(ch)){
                count.put(ch, count.get(ch)+1);
            }else{
                count.put(ch, 1);
            }
        }
        
        for(int i=0; i<s.length(); i++){
            if(count.get(s.charAt(i)) == 1){
                return i;
            }
        }
        return -1;
        // using linked hash map
        /*
        Map<Character, Integer> count = new LinkedHashMap<>();
        for(char ch: s.toCharArray()){
            if(count.containsKey(ch)){
                count.put(ch, count.get(ch)+1);
            }else{
                count.put(ch, 1);
            }
        }
        
        for(char x: count.keySet()){
            if(count.get(x) == 1){
                return s.indexOf(x);
            }
        }
        return -1;
        */
    }
}