class Solution {
public:
    bool checkString(string s) {
       
        int ansa=INT_MAX;
        int ansb=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                ansa=i;
                break;
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='a'){
                ansb=i;
                break;
            }
        }
        if(ansb<ansa){
            return true;
        }
        return false;
    }
};