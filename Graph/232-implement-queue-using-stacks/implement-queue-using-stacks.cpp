class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size() > 1){
            s2.push(s1.top());
            s1.pop();
        }
        int k = s1.top();
        s1.pop();
        
        while(s2.size() > 0){
            s1.push(s2.top());
            s2.pop();
        }

        return k;

    }
    
    int peek() {
        while(s1.size() > 0){
            s2.push(s1.top());
            s1.pop();
        }

        int k = s2.top();

        while(s2.size() > 0){
            s1.push(s2.top());
            s2.pop();
        }

        return k;
    }
    
    bool empty() {
        return (s1.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */