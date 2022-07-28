class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<int,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(m.find(t[i])!=m.end()){
                if(m[t[i]]>0)
                m[t[i]]--;
                else
                    m.erase(t[i]);
            }
            else
                return false;
        }
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>0){
            return false;
        }
    }
        return true;
    }
};
//m2
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length()) return false;
//         int n = s.length();
//         int counts[26] = {0};
//         for (int i = 0; i < n; i++) { 
//             counts[s[i] - 'a']++;
//             counts[t[i] - 'a']--;
//         }
//         for (int i = 0; i < 26; i++)
//             if (counts[i]) return false;
//         return true;
//     }
// };