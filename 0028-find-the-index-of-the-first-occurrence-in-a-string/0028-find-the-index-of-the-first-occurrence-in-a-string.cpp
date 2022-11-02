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