class Solution {
public:
    //n*logn time n space
int nthUglyNumber(int n) {
//see earlier solution also using dp
    if(n<=6){
        return n;
    }
    
    // Priority Queue because we need numbers in sorted order...min first.
    priority_queue<long,vector<long>, greater<long>> q;
    
    // We use map for storing the element, which element is present in queue or not.
    unordered_map<long,int> m;
    
    q.push(1);
    m[1]++;
    
    long temp = 1;
    
    // For loop from 0 to n because we need nth ugly number.
    for(int i=0; i<n; i++){
        
        temp = q.top();
        q.pop();
        
        // Only insert in queue, when not visited. 
        if(m.find(temp*2)==m.end()){
            q.push(temp*2);
            m[temp*2]++;
        }
        
        if(m.find(temp*3)==m.end()){
            q.push(temp*3);
            m[temp*3]++;
        }
        
        if(m.find(temp*5)==m.end()){
            q.push(temp*5);
            m[temp*5]++;
        }
    }
    
    return temp;
    
}
};