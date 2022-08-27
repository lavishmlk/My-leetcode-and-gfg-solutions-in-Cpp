class MinStack {
public:
    //striver
    //not intuitive at all
    stack < long long > st;
  long long mini;
    MinStack() {

         mini = INT_MAX;
    }
    
    void push(int value) {
           long long val =value;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
          //we will store a updatedvalue , and focus what is val and min here bcz these will be used in pop for understanding
          //this mini is previous mini
          
       st.push(2 * val - mini);
          //in mini we will stre the original value
        mini = val;
      } else {
        st.push(val);
      }
    }
    }
    
    void pop() {
        if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
        //we wantprevious min after poppping
        // it will guve previous mini bcz its basically 2*mini-(2*val-mini) where mini was previous min and val was the current val at that time which we stored in mini 
      mini = 2 * mini - el;
    }   
    }
    
    int top() {
            if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
    }
    
    int getMin() {
           return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */