class Solution {
public:
    //see recursive solution also just previous submitted code
    string removeDuplicateLetters(string s) {
        
        //youtube pepcoding
        //using stack->
        //logic is: hume mainly stack me push karne hai elements agar wo st.top wle element se bada hai aur abhi tak nahi aya to(ye check karne ke liye exist array banaya hai)
        //else agar wo pehle aa chuka hai tab nahi aega doobara aur ya fir agar st.top ka element present element jo push karna hai usse bada hai to check ki st.top wla element aage future me aega(ye check karne ke liye freq array banaya hai)? agar aaega to baad me push kar denge abhi st.pop karde 
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