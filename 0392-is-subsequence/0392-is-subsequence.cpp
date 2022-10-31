class Solution {
public:
    
   bool helper(string s,string t,int index1,int index2){
        
        if(index1==s.length()){
            return true;
        }
        if(index2==t.length()){
            return false;
        }
        bool val=false;
       if(s[index1]==t[index2]){
        return helper(s,t,index1+1,index2+1);
       }
        else{
           return helper(s,t,index1,index2+1);
        }
    }
    
    bool isSubsequence(string s, string t) {
        if(s.length()==0){
            return true;
        }
        if(t.length()==0){
            return false;
        }
       return helper(s,t,0,0);
        
    }
};