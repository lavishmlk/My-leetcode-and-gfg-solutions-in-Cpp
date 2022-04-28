class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left=0;
        unordered_map<char,int>m;
        int maxLength=0;
        
        for(int right=0;right<s.length();right++){
            
            m[s[right]]++;
            
            while(m[s[right]]>1){
               
                m[s[left]]--;
                left++;
            }
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};