class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        // int* freq=new int[26];
       vector<int>freq(26,0);
       vector<bool>exists(26,false);   
        stack<char>st;
        for(int i=0;i<s.length();i++){   
        freq[s[i]-'a']++;
        }
        
        for(int i=0;i<s.length();i++){
             freq[s[i]-'a']--;
            if(exists[s[i]-'a']==true)
                continue;
        
           while(st.size()>0 && freq[st.top()-'a']>0 && st.top()>s[i]){
                exists[st.top()-'a']=false;
                // freq[st.top()]++;
                st.pop();
            }
            st.push(s[i]);
            exists[s[i]-'a']=true;
        }
        string ans="";
        while(st.size()>0){
        ans=ans+st.top();
        st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};