//discuss ke kiya sab
//gfg pe ye same ques hai but iss ques me azxxxzy ke liye azxzy ans aega but gfg pr ay
//M1 stack discussion
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    
    string removeDuplicates(string str) 
    {
        stack<char> s;
        for(auto i:str)
        {
            if(s.empty())
                s.push(i);
            else
            {
                if(s.top()==i)
                {
                    s.pop();
                }
                else
                    s.push(i);
            }
        }
        string ans;
        while(!s.empty())
            ans+=s.top(),s.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//m2
// Solution 2:(Using String as Stack - Accepted)
// It is just the simple modification of above code,
// instead of using stack we can directly use the resultant string for performing pop and push operations.
// class Solution {
// public:
    
//     string removeDuplicates(string str) 
//     {
//         string ans;
//         for(auto i:str)
//         {
//             if(!ans.empty() and ans.back()==i)
//                 ans.pop_back();
//             else
//                 ans.push_back(i);
//         }
//         return ans;
//     }
// };


//m3 recursion-memory limit ecxceeded
// class Solution {
// public:
//     //discuss
//     //recursive tle
//     //agar equal nahi hai tabhji index bandhana hai else nahi badha taaki 1st test case me jab bb remove hoke aa ban jae tab aa bhi remove ho jae
//     string ans;
//     void go(string str,int idx)
//     {
//         if(idx>=str.length())
//         {
//             ans=str;
//             return;
//         }
//         if(str[idx]==str[idx+1])
//         {
//             if(idx==0)
//                 go(str.substr(idx+2),0);
//             else
//                 go(str.substr(0,idx)+str.substr(idx+2),0);
//         }
//         else
//         go(str,idx+1);
//     }
//     string removeDuplicates(string s) 
//     {
//         ans="";
//         go(s,0);
//         return ans;
//     }
// };

//M4 RECURSIVE ANOTHER WAY
//    string removeDuplicates(string S) {
//   for (auto i = 1; i < S.size();i++){
//     if (S[i - 1] == S[i]) 
// 	  return removeDuplicates(S.substr(0, i - 1) + S.substr(i + 1));
//   }
//   return S;
// }