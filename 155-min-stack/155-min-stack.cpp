class MinStack {
public:
    
    //M1 using 2 stacks
    //m2 using pair
    
    //m3
    //pepcoding(min stack-II)
    
    //val+val-previous_min is modified value
    //to get original value we we just return min coz min me original value padi hai
    //in pop->we have to revert back to previos min after popping so to get previos min we do-> 2*min-st.top() bcz st.top() contains 2*val-previos_min
    
        //we will store a updatedvalue i.e val+val-min in stack
//so basically stack me val honi chahiye thi par hume 2*val-min store kardia aur min me humne wo val store karli that is uss point tak ka minimum tha  
    
    //ye hame ye batata hai ki jab bhi stack me value min se choti hogi wahi point hai jahan humne modified value store ki thi
    
    
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
    long long topval = st.top();
    st.pop();

    if (topval < mini) {
      mini = 2 * mini - topval;
    }   
    }
    
    int top() {
            if (st.empty()) return -1;

    long long topval = st.top();
    if (topval < mini) return mini;
    return topval;
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