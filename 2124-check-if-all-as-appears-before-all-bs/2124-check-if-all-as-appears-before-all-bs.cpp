class Solution {
public:
    bool checkString(string s) {
       
        int ansa=INT_MAX;
        int ansb=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                ansa=i;
                break;
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='a'){
                ansb=i;
                break;
            }
        }
        if(ansb<ansa){
            return true;
        }
        return false;
    }
};


//M2
// class Solution
// {
// public:
// 	bool checkString(string s)
// 	{
// 		auto it = s.begin();

// 		while (it != s.end() && *it == 'a') ++it;

// 		while (it != s.end() && *it == 'b') ++it;

// 		return it == s.end();
// 	}
// };

//M3
// class Solution {
// public:
// bool checkString(string s) {
//    for(int i=0;i<s.size()-1;++i){
//       if(s[i]>s[i+1]) return false;  
//    }    
//   return true;
// }
// };


// m4
// bool checkString(string s) {
//         return is_sorted(s.begin(),s.end());
//     }