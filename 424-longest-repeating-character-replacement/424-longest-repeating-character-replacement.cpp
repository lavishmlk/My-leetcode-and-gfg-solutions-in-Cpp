class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxLength=0;
        
       for(int j=0;j<26;j++){
           
            int left=0;
      
       
            int notEqual=0;
           
           char ch=j+'A';
           
           for(int i=0;i<s.length();i++){
               
               if(s[i]!=ch){
                   notEqual++;
               }
               
               while(notEqual>k){
                   if(s[left]!=ch){
                       notEqual--;
                   }
                   left++;
               }
               maxLength=max(maxLength,i-left+1);
             
           }
       }
        return maxLength;
    }
};