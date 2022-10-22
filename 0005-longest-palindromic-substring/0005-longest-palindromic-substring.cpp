//https://leetcode.com/problems/longest-palindromic-substring/discuss/618232/Approach-1%3A-Using-Longest-Common-Substring-Concept

//longest common substring ko reverse karke longest common substring me hi pass kardia aur check kardlia ki palindrome hai ya nahi jo bhi common string aegi

//NOTE LONGEST PANIDROME SUBSEQUENCE ME FIRST STRING KO REVERSE KARKE PASS KARKE LCS CALL KAR DEGA TO ANS MIL JAEGA BUT LONGEST PALINDROME SUBSTRING ME AISA NAHI HAI REVERSE KARKE PASS KARKE LCS CALL KARNE KE BAAD BHI PALINDROME ALAG SE CHECK KARNA PADEGA ELSE IT WILL FAIL FOR THIS TESTCASE -> "aacabdkacaa"

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string s2=s;
        reverse(s2.begin(),s2.end());
        return LCSS(s,s2,n);
    }
    string LCSS(string s1, string s2, int n)
    {
        string ans;
        int DP[n+1][n+1],max=0;
        for(int i=0; i<=n; ++i)
        {
            for(int j=0; j<=n; ++j)
            {
                if(i==0 || j==0)
                    DP[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                {
                    DP[i][j]=1+DP[i-1][j-1];
                    if(DP[i][j]>max)
                    {
                        string temp=s1.substr(i-DP[i][j],DP[i][j]);
                        string revtemp=temp;
                        reverse(revtemp.begin(),revtemp.end());
                            if(revtemp==temp)
                            {
                                max=DP[i][j];
                                ans=temp;
                            }
                    }
                }
                else
                    DP[i][j]=0;
                
            }
        }
        return ans;
    }
};