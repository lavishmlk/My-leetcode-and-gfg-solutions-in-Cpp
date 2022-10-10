//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
      string temp="";
  map<char,int>m;

  for(int i=0;i<s.length();i++){
    
       m[s[i]]++;
      if(m.find(s[i])!=m.end()){
          if(m[s[i]]>1){
              temp=temp+s[i];
              return temp;
          }
      }
     
  }
  return "-1";
  
}
