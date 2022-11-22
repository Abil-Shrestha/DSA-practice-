//Leetcode 1290. Convert Binary Number in a Linked List to Integer (Easy)
const getDecimalValue = (head) => {
    let decimalVal = head.val;
    while (head.next != null){
        decimalVal=decimalVal*2+head.next.val;
        head=head.next;
    }
    return decimalVal;
};