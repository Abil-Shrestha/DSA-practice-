class Stack {
    constructor() {
        this.items = [];
    }

    // Add an item to the stack
    push(item) {
        this.items.push(item);
    }

    // Remove and return the top item from the stack
    pop() {
        if (this.isEmpty()) {
            throw new Error("Stack is empty");
        }
        return this.items.pop();
    }

    // Return the top item from the stack without removing it
    peek() {
        if (this.isEmpty()) {
            throw new Error("Stack is empty");
        }
        return this.items[this.items.length - 1];
    }

    // Check if the stack is empty
    isEmpty() {
        return this.items.length === 0;
    }

    // Return the number of items in the stack
    size() {
        return this.items.length;
    }

    // Empty the stack
    clear() {
        this.items = [];
    }
}

// Example usage
const stack = new Stack();
stack.push("apple");
stack.push("banana");
stack.push("orange");

console.log(stack.pop()); // "orange"
console.log(stack.peek()); // "banana"
console.log(stack.size()); // 2