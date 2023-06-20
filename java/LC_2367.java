class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        HashSet<Integer> hasmap = new HashSet<>();
        int count = 0;
        for(int i = 0;i<nums.length;i++){
            if(hasmap.contains(nums[i]-diff) && hasmap.contains(nums[i]-(2*diff))){
                count++;
            }
            hasmap.add(nums[i]);
        }
        return count;
        
    }
}