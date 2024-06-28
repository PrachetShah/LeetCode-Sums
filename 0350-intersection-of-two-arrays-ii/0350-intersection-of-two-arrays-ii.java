class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
       Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        List<Integer> res = new ArrayList<>();
        int i=0, j=0;
        
        while(i<nums1.length && j<nums2.length){
//             if num1 < nums2
            if(nums1[i] < nums2[j]){
                i++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
//                 else intersection and increment both
                res.add(nums1[i]);
                i++;
                j++;
            }
        }
        
        int[] out = new int[res.size()];
        for(i=0; i<res.size(); i++){
            out[i] = res.get(i);
        }
        return out;
    }
}