class Solution {
public:
    //ayushi youtube
  int titleToNumber(string columnTitle) {
        int result=0;
        for(int i = 0; i < columnTitle.size(); i++){
            result*=26;
            result+=(columnTitle[i]-'A'+1);
        }
        return result;
    }
};