class Solution {
public:
    //by my own
   bool helper(string s,string t,int index1,int index2,vector<vector<int>> &v){
        
        if(index1==s.length()){
            return true;
        }
        if(index2==t.length()){
            return false;
        }
       if(v[index1][index2] != -1)
            return v[index1][index2];
       
       if(s[index1]==t[index2]){
        return v[index1][index2] =helper(s,t,index1+1,index2+1,v);
       }
        else{
           return v[index1][index2] =helper(s,t,index1,index2+1,v);
        }
    }
    
    bool isSubsequence(string s, string t) {
            int m = s.length();
        int n = t.length();
        if(s.length()==0){
            return true;
        }
        if(t.length()==0){
            return false;
        }
        
         vector<vector<int>> v(m+1,vector<int> (n+1,-1));
       return helper(s,t,0,0,v);
        
    }
};