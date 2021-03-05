#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while( !outStack.empty()) {
            inStack.push(outStack.top());
            outStack.pop();
        }
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while( !inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        while( !inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
        int x = outStack.top();
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(inStack.empty()) {
            return outStack.empty();
        } else {
            return false;
        }
    }
};

int main() {
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    mq.push(3);
    mq.push(4);
    cout << mq.peek() << endl;
    cout << mq.pop() << endl;
    cout << mq.pop() << endl;
    cout << mq.pop() << endl;
    cout << mq.pop() << endl;
    cout << mq.empty() << endl;
    mq.push(5);
    mq.push(6);
    mq.push(7);
    cout << mq.pop() << endl;

}
