class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int>m;
        
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
    
        int i;
        int ans=0;
        for(i=0;i<s.length()-1;i++){
            if(m[s[i]]<m[s[i+1]]){
               ans=ans-m[s[i]];
               ans=ans+m[s[i+1]];
                i++;
            }
            else{
                ans=ans+m[s[i]];
            }
        }
        if(i==s.length()-1){
            ans=ans+m[s[i]];
        }
        return ans;
    }
};