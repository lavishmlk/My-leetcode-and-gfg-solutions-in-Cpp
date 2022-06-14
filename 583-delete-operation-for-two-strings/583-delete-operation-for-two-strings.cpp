class Solution {
public:
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
    
    int minDistance(string word1, string word2) {
          int m=word1.size();
        int n=word2.size();
        int arr[1001][1001];   
          for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                arr[i][j]=-1;
            }
        }
   int val=lcs(word1,word2,m,n,arr);
        int noofdeloperations=(word1.size()-val)+(word2.size()-val);
        return noofdeloperations;
    }
};

