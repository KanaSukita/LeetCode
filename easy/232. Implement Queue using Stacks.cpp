// Implement the following operations of a queue using stacks.
// 
// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
// Notes:
// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).



// Idea:
// two stacks as input and output

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = peek();
        output.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if (output.empty()){
            while (input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
private:
    stack<int> input, output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */