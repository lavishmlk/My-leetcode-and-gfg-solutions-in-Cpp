class Solution {
public:
    //kmp subhesh pepcoding
    // solution:- https://leetcode.com/problems/repeated-substring-pattern/discuss/1694256/Java-KMP-solution-with-explanation
    //tc-O(n)
    bool repeatedSubstringPattern(string s) {
        
      int n = s.length(), len = 0, i = 1;
        int* lps = new int[n+1];
        lps[0]=0;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else{
                if (len> 0) {
                      len = lps[len - 1];
            } else { 
                    lps[i] = 0;   
                i++;
            }
            } 
        }
        return lps[n - 1] > 0 && n % (n - lps[n - 1]) == 0;
    }
};