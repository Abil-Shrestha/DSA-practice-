//Leetcode 234. Palindrome Linked List (Easy)
var isPalindrome = function(head) {
    let arr =[]
    let slow = head;
    let fast=head;
    while(fast){
        if(fast.next == null){
            slow= slow.next;
            break;
        }
        arr.push(slow.val);
        slow=slow.next;
        fast=fast.next.next;
        
    }
    while(slow){
        if(arr.pop()! slow.val) return false;
        slow=slow.next;
    }
    return true;
    
    
};