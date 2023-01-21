var searchInsert = function(nums, target) {
    let result=0;
    for(let i=0;i<nums.length;i++){
        if(nums[i]==target){
            result=i;
            break;
        } else {
            if((nums[i]+1)== target){
                result=i+1;
                break;
            } else if ((nums[i]-1)==target){
                result=i;
                break;
            } else if(nums[i]<target){
                result=i+1;
            }
        }
    }
    if (result<0){
        result=0;
    }
    return result;
};