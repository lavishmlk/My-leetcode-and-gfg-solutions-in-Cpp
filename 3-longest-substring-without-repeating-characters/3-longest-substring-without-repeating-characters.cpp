class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        int low=0;
        int high=1;
       set<int>m;
        m.insert(s[low]);
        int length=1;
        while(high<s.length() && low<s.length()){
            
            if(m.find(s[high])!=m.end()){
                 
                  
                m.erase(s[low]);
                 low++;
            }
            else{
                length=max(length,high-low+1);
                 m.insert(s[high]);  
                high++;
            }
           
            
        }
        return length;
    }
};