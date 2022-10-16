class Solution {
public:
    //using leetcode 516 and av logic
    int lcs(string &text1, string &text2,int m,int n,int t[][1001]){
        
        if(m==0 || n==0){
            return 0;
        }
        
        if(t[m][n]!=-1){
            return t[m][n];
        }
        
        if(text1[m-1]==text2[n-1]){
          return t[m][n]=1+lcs(text1,text2,m-1,n-1,t);
        }
        else{
           return t[m][n]=max(lcs(text1,text2,m-1,n,t),lcs(text1,text2,m,n-1,t));
        
        }
    }
    int longestPalindromeSubseq(string s) {
        string a=s;
            int m=s.size();
             int arr[1001][1001];   
          for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                arr[i][j]=-1;
            }
        }
        reverse(s.begin(),s.end());
               return lcs(s,a,m,m,arr);
    }
    
    int minInsertions(string s) {
        int val=longestPalindromeSubseq(s);
        return s.length()-val;
    }
};