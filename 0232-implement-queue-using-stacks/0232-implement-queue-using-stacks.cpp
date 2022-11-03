class MyQueue {
public:
         stack<int>stk1;
        stack<int>stk2;
    MyQueue() {
   
    }
    
    void push(int x) {
         stk1.push(x);
    }
    
    int pop() {
        
        if(stk2.size()==0){
        while(stk1.size()>0){
            stk2.push(stk1.top());
            stk1.pop();
        }
        }
        int val=stk2.top();
         stk2.pop();
        return val;
    }
    
    int peek() {
             if(stk2.size()==0){
        while(stk1.size()>0){
            stk2.push(stk1.top());
            stk1.pop();
        }
        }
        return stk2.top();
    }
    
    bool empty() {
      if(stk1.size()==0 && stk2.size()==0)
          return true;
        
        return false;
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