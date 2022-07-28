class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<int,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(m.find(t[i])!=m.end()){
                if(m[t[i]]>0)
                m[t[i]]--;
                else
                    m.erase(t[i]);
            }
            else
                return false;
        }
       for(int i=0;i<m.size();i++){
           if(m[i]>0){
               return false;
           }
           
       }
        return true;
    }
};