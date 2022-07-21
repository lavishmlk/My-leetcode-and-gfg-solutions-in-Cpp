class Solution {
public:
    //using recursion in  pepcoding printEncodings but it will give tle
//can do it withput taking index like s.substr(0,1) and s.substr(1) like i did in prev code but with idx its easy
    //video 4
int printEncoding(string str,int dp[],int idx){
          
  if(str.length()==idx){
      
      return 1;
  }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    
int val1=0; int val2=0;
  if(str[idx]!='0')
    val1= printEncoding(str,dp,idx+1);
    
    if(idx+1<str.length() && str[idx]!='0' ){
        string str2=str.substr(idx,2);
        cout<<str2<<" ";
        if(stoi(str2)>=10 && stoi(str2)<=26 )
        val2=printEncoding(str,dp,idx+2);
    }
    
return dp[idx]=val1+val2;
    }
    
    int numDecodings(string s) {
        int* dp=new int[s.length()+1];
        // memset(dp,-1,s.length()+1);
        for(int i=0;i<s.length()+1;i++){
            dp[i]=-1;
        }
      return  printEncoding(s,dp,0);

    }
};