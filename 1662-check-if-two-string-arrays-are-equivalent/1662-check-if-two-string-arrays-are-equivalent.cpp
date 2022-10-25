class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string str1,str2;
        
        for(int i=0;i<word1.size();i++){
            for(char c:word1[i]){
               str1+=c;
            }
        }
        
            for(int i=0;i<word2.size();i++){
            for(char c:word2[i]){
               str2+=c;
            }
        }         
  if(str1==str2){
      return true;
  } 
        return false;
    }
};