class MyCalendar {
    //code with alisha
    //due to map elements will be sorted and in those elements we will store +1 and -1
    private:
    map<int,int>m;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       
   m[start]++;
        m[end]--;
        int sum=0;
        for(auto it=m.begin();it!=m.end();it++){
        sum+=it->second;
            if(sum>1){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */