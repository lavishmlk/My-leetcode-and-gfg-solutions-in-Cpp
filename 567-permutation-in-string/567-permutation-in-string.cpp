class Solution {
public:
    
    bool isequal(int *currFreq,int*reqFreq){
        for(int i=0;i<26;i++){
            if(currFreq[i]!=reqFreq[i]){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {

        // int Count=0;
        int* reqFreq=new int[27];
        int* currFreq=new int[27];
        
        for(int i=0;i<=26;i++){
            reqFreq[i]=0;
            currFreq[i]=0;
        }
        
        int window=s1.length();
        
         for(int i=0;i<s1.length();i++){
        reqFreq[s1[i]-'a']++;
        }
        
        // for(int i=0;i<window;i++){
        // currFreq[s2[i]-'a']++;
        // }
        
        // for(int i=0;i<window;i++){
        // if(reqFreq[s2[i]]==currFreq[s2[i]]){
        //     Count++;
        // }
        // }
        // if(Count==s1.length()){
        //     return true;
        // }
        
        for(int i=0;i<s2.length();i++){
            if(i<window){
                  currFreq[s2[i]-'a']++;
            }
            else{
                 currFreq[s2[i]-'a']++;
                 currFreq[s2[i-window]-'a']--;
            }
          
            //     if(currFreq[s2[i-window]]==reqFreq[s2[i-window]]){
            //     Count--;
            // }
           
            
            // if(currFreq[s2[i]]==reqFreq[s2[i]]){
            //     Count++;
            // }
        
            // if(Count==s1.length()){
            //     return true;
            // }
            if(isequal(currFreq,reqFreq)==true){
                return true;
            }
        }
        
      return false;  

    }
};