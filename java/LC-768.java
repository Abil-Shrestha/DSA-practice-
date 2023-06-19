class Solution {
    public int maxChunksToSorted(int[] arr) {
        int numchunks = 0;
        for(int i= 0;i<arr.length;i++){
            int max = arr[i];
            int numToComp = arr[i];
            for(int j =i +1 ; j< arr.length; j++){
                if(arr[j]< numToComp){
                    i = j;
                    numToComp = max;
                } else{
                    max = Math.max(arr[j],max);
                }
            }
            numchunks++;
        }
        return numchunks;
    }
}