// Time Complexity O(n * m) where n is length of haystack and m is length of needle
// Space complexity O(1)
//two pointer approach from discuss

class Solution {
public:
    int strStr(string haystack, string needle) {
        	if(needle.length() == 0) {
			return 0;
		}
		if(haystack.length() < needle.length()) {
			return -1;
		}
		if(haystack.length() == needle.length()) {
			return haystack==needle ? 0 : -1;
		}
		for(int i=0; i < haystack.length(); i++) {
			int hIndex = i;
			int nIndex = 0;
			while(hIndex < haystack.length() && nIndex < needle.length() && haystack[hIndex] == needle[nIndex]) {
				hIndex++;
				nIndex++;
			}
			if(nIndex == needle.length()) {
				return i;
			}
		}
		return -1;
    }
};

//m2 gfg
//similar to upper codejust different way
// C++ program to check if a string is
// substring of other.
// #include <bits/stdc++.h>
// using namespace std;

// // Returns true if s1 is substring of s2
// int isSubstring(string s1, string s2)
// {
// 	int M = s1.length();
// 	int N = s2.length();

// 	/* A loop to slide pat[] one by one */
// 	for (int i = 0; i <= N - M; i++) {
// 		int j;

// 		/* For current index i, check for
// pattern match */
// 		for (j = 0; j < M; j++)
// 			if (s2[i + j] != s1[j])
// 				break;

// 		if (j == M)
// 			return i;
// 	}

// 	return -1;
// }

// /* Driver code */
// int main()
// {
// 	string s1 = "for";
// 	string s2 = "geeksforgeeks";
// 	int res = isSubstring(s1, s2);
// 	if (res == -1)
// 		cout << "Not present";
// 	else
// 		cout << "Present at index " << res;
// 	return 0;
// }

//m3 stl for oa's
//tc-shyd O(n)
//bro coders-https://www.youtube.com/watch?v=AZuZZgUrQTo&list=PLjeQ9Mb66hM05uqfKysHKi3eA5HhK7QSy&index=9 -after 4:30

//m4 
//kmp