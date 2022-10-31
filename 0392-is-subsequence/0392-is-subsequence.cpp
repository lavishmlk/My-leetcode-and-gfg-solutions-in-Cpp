class Solution {
public:
    //by my own
   bool helper(string s,string t,int index1,int index2,vector<vector<int>> &v){
        
        if(index1==s.length()){
            return true;
        }
        if(index2==t.length()){
            return false;
        }
       if(v[index1][index2] != -1)
            return v[index1][index2];
       
       if(s[index1]==t[index2]){
        return v[index1][index2] =helper(s,t,index1+1,index2+1,v);
       }
        else{
           return v[index1][index2] =helper(s,t,index1,index2+1,v);
        }
    }
    
    bool isSubsequence(string s, string t) {
            int m = s.length();
        int n = t.length();
        if(s.length()==0){
            return true;
        }
        if(t.length()==0){
            return false;
        }
        
         vector<vector<int>> v(m+1,vector<int> (n+1,-1));
       return helper(s,t,0,0,v);
        
    }
};

//BY Aditya verma video 31
// class Solution {
// public:
    
//         int lcs(string &text1, string &text2,int m,int n){
        
//       int t[m+1][n+1];
//         for(int i=0;i<=m;i++)
//         {
//         for(int j=0;j<=n;j++){
//                   if(i==0 || j==0){
//             t[i][j]=0;
//         }
//         }
//         }
     
        
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=n;j++){
//                  if(text1[i-1]==text2[j-1]){
//           t[i][j]=1+t[i-1][j-1];
//         }
//         else{
//           // t[m][n]=max(t[m-1][n],t[n][m-1]);
//              t[i][j]=max(t[i-1][j],t[i][j-1]);
        
//         }
//             }
//         }
//         return t[m][n];
       
//     }
    
//     bool isSubsequence(string s, string t) {
//            int m=s.size();
//         int n=t.size(); 
       
//    int lengthoflcs=lcs(s,t,m,n);
//         if(lengthoflcs==m){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };