//Leetcode 20. Valid Parentheses (Easy)
const isValid = (s) => {
    let hashMap  = {"(":")","[":"]","{":"}"}
    let stack = [];
    for(let c of s){
        if(hashMap[c]){
            stack.push(hashMap[c]);
        } else  if(stack.length>0 && stack[stack.length-1] === c){
            stack.pop();
        } else{
            return false;
        }
    }
    
    return (stack.length === 0);
};