//leetcode 876. Middle of the Linked List (Easy)
const middleNode = (head) => {
    let fast = head;
    let slow = head;
  
    while (fast && fast.next) {
      slow = slow.next;
      fast = fast.next.next;
    }
    return slow;
  };