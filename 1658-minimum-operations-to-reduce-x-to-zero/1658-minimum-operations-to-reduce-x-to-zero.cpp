class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        
        if(x>sum){
           return -1; 
        }
        
        int find_longest_subarray=sum-x;
        unordered_map<int,int>m;
        
        //map value and index are stored in map
        m[0]=0;
        
        int summ=0;
        int longest=0;
        for(int i=0;i<nums.size();i++){
            
            summ=summ+nums[i];
            
            if(m.find(summ-find_longest_subarray)!=m.end()){
                if(summ-find_longest_subarray==0)
              longest=max(longest,i- m[summ-find_longest_subarray]+1); 
                else
                   longest=max(longest,i- m[summ-find_longest_subarray]);    
            }
            
            m[summ]=i;    
        
        }
        return longest==0?(find_longest_subarray==0?n:-1):n-longest;
                
    }
};