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



//m2 without dp
//ayushi youtube
// logic=> choose a point and compare i-1 and i+1 from odd length palindrome and i-1 and i for even length palidrome
// class Solution {
// public:
//     //from ayushi sharma
//     string longestPalindrome(string s) {
//         int n = s.length();
//         if(n==1) return s;
//         string ans = "";
//         // low and high points to the starting & ending indices of the pallindromic substrings 
//         int low, high;
//         // starting index of the max length pallindromic substring
//         int start_index;
//         // max length of the pallindromic substring
//         int max_length = 0;
//         for(int i = 1; i < n; i++)
//         {
//             // for odd length substrings
//             // choose i as epicenter and move left and right checking the string is pallindrome or not
//             low = i - 1;
//             high = i + 1;
//             while(low >= 0 && high < n && s[low] == s[high])
//             {
//                 if(max_length < high - low + 1)
//                 {
//                     max_length = high - low + 1;
//                     start_index = low;
//                 }
//                 --low;
//                 ++high;
//             }
//             // for even length substrings
//             // choose i-1 and i as epicenters and move left and right checking the string is pallindrome or not
//             low = i - 1;
//             high = i;
//             while(low >= 0 && high < n && s[low] == s[high])
//             {
//                 if(max_length < high - low + 1)
//                 {
//                     max_length = high - low + 1;
//                     start_index = low;
//                 }
//                 --low;
//                 ++high;
//             }
//         }
//         // if there is no pallindromic substring present of size >= 2 
//         if(max_length == 0)
//         {
//             ans += s[0];
//             return ans;
//         }
//         for(int i = start_index; i < start_index + max_length; i++)
//         {
//             ans += s[i];
//         }
//         return ans;
//     }
// };