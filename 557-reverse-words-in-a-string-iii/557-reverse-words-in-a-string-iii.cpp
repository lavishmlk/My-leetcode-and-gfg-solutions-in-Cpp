class Solution {
public:
    
//     string Reverse(string &str){
        
//         int length=str.length();
//         int i=0;
//         int j=length-1;
//         while(i!=j){
//             swap(str[i],str[j]);
//             i++;
//             j--;
//         }
//         return str;
//     }
    
    string reverseWords(string s){
        
        string ans="";
        string finalval="";
        for(auto x:s){
            if(x==' '){
               // Reverse(ans);
                 reverse(ans.begin(),ans.end());
                finalval=finalval+ans+" ";
                ans="";
            }
            else{
                ans=ans+x;
            }
        }
         reverse(ans.begin(),ans.end());
        finalval+=ans;
        return finalval;
    }
};