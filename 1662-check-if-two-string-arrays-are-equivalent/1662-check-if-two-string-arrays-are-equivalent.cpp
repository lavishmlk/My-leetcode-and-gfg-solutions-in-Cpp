
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0; // word pointers
        int m = 0, n = 0; // char pointers
        
        while (i < word1.size() and j < word2.size()) {            
            if (word1[i][m++] != word2[j][n++])
                return false;
            
            if (m >= word1[i].size())
                i++, m = 0;
            
            if (n >= word2[j].size())
                j++, n = 0;
        }
        
        return i == word1.size() and j == word2.size();
    }
};


//m2
// class Solution {
// public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
//         string str1, str2;
        
//         for( auto w1 : word1 ){
//             str1 += w1;
//         }
        
//         for( auto w2 : word2 ){
//             str2 += w2;
//         }
        
//         return str1 == str2;
//     }
// };

//by me
// class Solution {
// public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
//         string str1,str2;
        
//         for(int i=0;i<word1.size();i++){
//             for(char c:word1[i]){
//                str1+=c;
//             }
//         }
        
//             for(int i=0;i<word2.size();i++){
//             for(char c:word2[i]){
//                str2+=c;
//             }
//         }         
//   if(str1==str2){
//       return true;
//   } 
//         return false;
//     }
// };