class Solution {
public:
    bool isPossible(vector<int>& target) {
       
             priority_queue<int>pq;
        
        long long sum=0;
        
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            pq.push(target[i]);
        }
        
        while(pq.top()!=1){
            
            int value=pq.top();
            sum=sum-value;
            
            if(sum==1){
                return true;
            }
            
            if(sum>=value || sum==0){
                return false;
            }
          if(sum != 1 && value%sum == 0) return false;
            
            value%=sum;
           
            pq.pop();
            pq.push(value);
             sum=sum+value;
        }
        return true;
    }
};