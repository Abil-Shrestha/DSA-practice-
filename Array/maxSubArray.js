//leetcode 53.Maximum Subarray
const maxSubArray = (nums) => {
    let n = 0; // variable to store the previous value
    let max = -Infinity; // variable to store the max value
    for(let i=0;i<nums.length;i++){
        n = Math.max(n+nums[i],nums[i]); // comparing the max between current value and previous
        max = Math.max(max,n); // comparing the max between previous max and new max
    }
    return max;
};