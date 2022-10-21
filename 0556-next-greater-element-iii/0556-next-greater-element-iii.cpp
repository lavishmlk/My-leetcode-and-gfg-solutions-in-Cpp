

class Solution {
public:
    //pepcoding
    //traverse from last till we dont get a dip soppose we get a dip at i
    //after that travel again from last and find next greater element and swap it with element[i]
    //now reverse the number after i to make it smalleest among the greater permutations possible
    int nextGreaterElement(int num) {
          string s = to_string(num);
        int i = s.length() - 2;
        while(i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        
        if(i >= 0) {
            int k = s.length() - 1;
            while(s[k] <= s[i]) {
                k--;
            }
            char temp = s[i];
            s[i] = s[k];
            s[k] = temp;
        } else {
            return -1;
        }
        
        string res = "";
        for(int j = 0; j <= i; j++) {
            res += s[j];
        }
        
        for(int j = s.length() - 1; j > i; j--) {
            res += s[j];
        }
        
      if(stol(res)>INT_MAX){
          return -1;
      }
        else{
            return stol(res);
        }
//         if(num < 12)return -1;
        
//         string s = to_string(num);
        
//         int n = s.size();
        
//         int i = n-2;
        
//         while(i>=0 && s[i]>=s[i+1])
//             i--;
        
        
//         if(i<0)
//             return -1;
        
//         int j = n-1;
        
//         int k;
        
//         char max = '-';
        
//         while(i<j){
            
//             if(s[i]<s[j]){
                
//                 if(max == '-'){
//                     k = j;
//                     max = s[j];
//                 }else if(s[j]<max){
//                     k = j;
//                     max = s[j];
//                 }
                
//             }
            
//             j--;
//         }
//         swap(s[i],s[k]);
        
//         i = j+1;
//         j = n-1;
        
//         while(i<j){
//             swap(s[i],s[j]);
//             i++;j--;
//         }
        
//         long ans = stol(s);

//         if(ans>INT_MAX)return -1;
        
//         return ans;
    }
};