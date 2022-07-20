class Solution {
public:
    //discuss https://leetcode.com/problems/number-of-matching-subsequences/discuss/1187536/c%2B%2B-two-approaches-best-explained-why-simple-brute-force-will-give-TLE
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0,
        k=s.size();
    
      unordered_map<string,int>mymap;
      for(int i=0;i<words.size();i++)
        mymap[words[i]]++;
      for(auto x:mymap)
      {
        int startOfS=0,startOfW=0;
        string w=x.first;
        int wSize=w.size();
        while(startOfS<k&&startOfW<wSize)
        {
          if(w[startOfW]==s[startOfS])
            startOfS++,startOfW++;
          else
            startOfS++;
        }if(startOfW==wSize)
          count+=x.second;//if we reach the length of string p then this word in in our string s. so we increase our count by number of times it occured in words instead of increamenting by 1
      }return count;
    }
};

//i did a mistake i filled s in map instead of words so that will no rum for testcases having duplicate elements in words like bb
// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
        
//     unordered_map<char,int>m;
        
//         for(int i=0;i<s.length();i++){
//             m[s[i]]++;
            
//         }
     
//         int count=0;
//         for(int i=0;i<words.size();i++){
//                int flag=0;
//             for(auto val:words[i]){
//             if(m.find(val)==m.end()){
//                 flag==1;
//              break;
                
//             }
//              }
//              if(flag==0){
//                  count++;
//                 cout<<count<<" "<<i<<endl;
//             }
//         }
//         return count;
//     }
// };