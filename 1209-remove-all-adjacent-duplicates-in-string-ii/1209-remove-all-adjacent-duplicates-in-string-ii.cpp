class Solution {
public:
    //ayushi youtute tc-n sc-n
    //basically stack me elements count ke saath push kar jaise hi cound k ke equal ho jae then pop
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>>st;
        int i=0;
       while(i<s.size()){
            if(st.size()>0 && st.top().first==s[i]){
                pair<char,int> val=st.top();
                st.pop();
                val.second+=1;
                st.push({s[i],val.second});
            }
            else{
                st.push({s[i],1});
            }
           if(st.top().second==k){
               st.pop();

           }
            i++;
        }
        string ans="";
        while(st.size()>0){
            pair<char,int> val=st.top();
            st.pop();
            while(val.second--){
            ans+=val.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// class Solution {
// public:
//     //recursion-youtube algorithms made easy
//    // gives tle
//     string removeDuplicates(string s, int k) {
//                 int count = 1;
//         for(int i=1;i<s.length();i++){
//             if(s[i]==s[i-1]){
//                 count++;
//             }
//             else{
//                 count=1;
//             }
            
//             if(count==k){
//                 string reduced = s.substr(0,i-k+1) + s.substr(i+1);
//                 return removeDuplicates(reduced,k);
//             }
//         }
        
//         return s;
//     }
// };