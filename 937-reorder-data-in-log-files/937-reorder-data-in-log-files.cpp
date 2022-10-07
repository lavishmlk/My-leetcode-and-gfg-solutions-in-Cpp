   bool comp(string &a, string &b){
    int p1 = a.find(' ');
    int p2 = b.find(' ');
    string s1 = a.substr(p1+1);
    string s2 = b.substr(p2+1);
    if(s1==s2) return  a < b;
    return s1 < s2;
}
    

class Solution {
public:
  //https://leetcode.com/problems/reorder-data-in-log-files/discuss/929344/C%2B%2B-oror-Easy-to-understand-oror-custom-comparator-for-sort-function  
 
    //refer this 
    //for insert->https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/
    //https://www.geeksforgeeks.org/substring-in-cpp/
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter;
        vector<string> digits;
        vector<string> res;
        for (int i = 0; i < logs.size(); i++){
            int pos = logs[i].find(' ');
            if (logs[i][pos+1] >= '0' and logs[i][pos+1] <='9'){
                digits.push_back(logs[i]);
            }
            else{
                letter.push_back(logs[i]);
            }
        }
        sort(letter.begin(), letter.end(), comp);
        res.insert(res.end(),letter.begin(),letter.end());
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};