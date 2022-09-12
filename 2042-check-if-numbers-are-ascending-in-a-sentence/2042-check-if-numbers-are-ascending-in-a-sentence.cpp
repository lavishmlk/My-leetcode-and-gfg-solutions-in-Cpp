class Solution {
public:
    bool areNumbersAscending(string s) {
        
   string ans="";
        vector<int>v;
         s.push_back(' ');
        for(int i=0;i<s.length();i++){         
            
            if(isdigit(s[i])){
                
                ans+=s[i]; 
            }
               if(ans.size()>0 && s[i]==' '){
                int a=stoi(ans);
                v.push_back(a);
                ans="";
             }
         
 }
        cout<<v.size()<<endl;
       for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1])return false; //check whether the array is sorted or not
        }
        return true;
    }
};